/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapfenni <mapfenni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:51:00 by gfabre            #+#    #+#             */
/*   Updated: 2024/02/29 01:51:05 by mapfenni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include "stdio.h"
# include "mlx/mlx_linux/mlx.h"
# include "gnl/get_next_line.h"

# define MINIMAPSIZE 10

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
}				t_img;

typedef struct s_texture
{
	char	*no_path;
	char	*so_path;
	char	*we_path;
	char	*ea_path;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}				t_texture;

typedef struct s_cub
{
	t_texture	*txtr;
	t_color		*f;
	t_color		*c;
	float		pos[2]; // x - , y | 
	float		dir; // NSEW (0, 90, 180, 270) remplir pendant juste avant floodfill
	char		**map;
	void		*mlx;
	void		*win;
	t_img		*img_map;
	t_img		*img0;
	t_img		*img1;
	int			img_x;
	int			img_y;
	int			error; //pour noter si le programme doit exit (si il trouve au moins une erreur) (error++ demande a manoug)
}				t_cub;



// checker si dans la ligne de l'élément il y a plus que juste RGB (ex: NO 255,0,0,255)
// checke len vide mid map
// pendant flood si len de ligne suivant (tableau) inferieur a position actuelle alors error
// fichier des sprites doivent être en format ".xpm"


// initialise structures

t_cub		*init_cub(void);
t_texture	*init_texture(void);
t_color		*init_color(void);

// engine

void	setup_mlx(t_cub *cub);
void	start_mlx(t_cub *cub);
void	create_image(t_cub *cub);
void	create_window(t_cub *cub, char *name);
void	*ft_xpm_to_img(t_cub *cub, char *path);
void	set_imgs(t_cub *cub);
void	pixel_put(t_img *img, int x, int y, int color);
void	display_minimap(t_cub *cub, t_img *img);

// parsing

void	parsing(t_cub *cub, char **argv);

// free and exit

void	ft_exit(int code);
void	clean_exit(t_cub *cub, int sig);
void	check_error(char **argv);

#endif