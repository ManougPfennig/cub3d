/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:00 by gfabre            #+#    #+#             */
/*   Updated: 2024/03/12 18:11:22 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx_linux/mlx.h"

# define MAPSIZE 7
# define WIN_LEN 960
# define WIN_HEIGHT 704
# define FOV 66
// FOV peut être défini tel que :  n ∈ ]0;180[

# define LEFT_TURN 1
# define RIGHT_TURN 2
# define MOVE_SIZE 1

# define W_KEY 122
# define A_KEY 113
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define MAP_KEY 109
# define ESCAPE_KEY 65307

# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF

# define N_WALL 10
# define S_WALL 20
# define E_WALL 30
# define W_WALL 40

# ifndef M_PI
#  define M_PI 3.141592653589793
# endif 

typedef struct s_ray
{
	
	int		map[2];
	double	cameraX;
	double	sideDist[2];
	double	step[2];
	double	rayDir[2];
	double	deltaDist[2];
	double	plane[2];
	int		hit;
	int		type;
	double	distance;
}				t_ray;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}				t_img;

typedef struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	t_img	*no;
	t_img	*so;
	t_img	*we;
	t_img	*ea;
}				t_texture;

typedef struct s_cub
{
	t_texture	*txtr;
	t_color		*f;
	t_color		*c;
	double		pos[2];
	double		dir[2]; // NSEW (0, 90, 180, 270) remplir pendant juste avant floodfill
	char		**map;
	void		*mlx;
	void		*win;
	t_img		*img0;
	t_img		*img1;
	int			toggle_map;
	int			floor_clr;
	int			ceiling_clr;
	int			img_x;
	int			img_y;
	int			error; //pour noter si le programme doit exit (si il trouve au moins une erreur) (error++ demande a manoug)
	int			current_img;
}				t_cub;



// checker si dans la ligne de l'élément il y a plus que juste RGB (ex: NO 255,0,0,255)
// checke len vide mid map
// pendant flood si len de ligne suivant (tableau) inferieur a position actuelle alors error
// fichier des sprites doivent être en format ".xpm"


// initialise structures

t_cub		*init_cub(void);
t_texture	*init_texture(void);
t_color		*init_color(void);
t_img		*init_img(void);

// engine

void		start_mlx(t_cub *cub);
void		setup_mlx(t_cub *cub);
void		setup_img(t_cub *cub, t_img *img, int length, int height);
void		setup_mlx_event(t_cub *cub);
void		init_ceiling_floor_texture(t_cub *cub);
void		color_img(t_img *img, int color, int length, int height);
void		set_textures(t_cub *cub);
void		*ft_xpm_to_img(t_cub *cub, t_img *img, char *path);
void		create_window(t_cub *cub, char *name);
void		pixel_put(t_img *img, int x, int y, int color);
void		display_minimap(t_cub *cub, t_img *frame);
void		toggle_map_display(t_cub *cub);
void		move_player(t_cub *cub, float x, float y);
void		rotate_player(t_cub *cub, int dir);
void		raycasting(t_cub *cub, t_img *frame);
void		new_frame(t_cub *cub);
void		exit_game(t_cub *cub);
int			get_color(t_img *img, int x, int y);
void		put_img_to_frame(t_img *img, t_img *frame, int x, int y);


// parsing

void		parsing(t_cub *cub, char **argv);

// free and exit

void		ft_exit(int code);
void		clean_exit(t_cub *cub, int sig);
void		check_error(char **argv);

// get_next_line

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

char		*get_next_line(int fd);
char		*keep_first_nl(char *str);
int			check_no_nl(char *str);
char		*del_first_nl(char *str);
void		ft_freestr(char **ptr);
char		*ft_clean_up(char **ptr, char **ptr2);

#endif