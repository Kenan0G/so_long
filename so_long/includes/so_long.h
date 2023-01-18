/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:09:04 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/17 11:30:31 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include "get_next_line.h"
# define PLAYER	"./sprites/XPM/kratos.xpm"
# define GROUND "./sprites/XPM/ground.xpm"
# define COLLECT "./sprites/XPM/collect.xpm"
# define WALL "./sprites/XPM/wall.xpm"
# define EXIT "./sprites/XPM/exit.xpm"

typedef struct s_image
{
	void	*i_p;
	void	*i_g;
	void	*i_c;
	void	*i_w;
	void	*i_e;
}				t_image;

typedef struct s_mlx
{
	void	*m;
	void	*win;
}				t_mlx;

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		x;
	int		y;
	int		pos_player[2];
	int		nb_c;
	int		check;
	int		count;
	int		letter;
}				t_map;

typedef struct s_data_box
{
	t_map	*ma;
	t_image	*i;
	t_mlx	*m;
}				t_data_box;

char	**get_map(char *fd_char);
int		check_map(t_data_box *data);
int		nb_lines(t_data_box *data);
int		pars(t_data_box *data, char element);
int		start(t_data_box **data, char *fd);
int		pathfinding(t_data_box *data);
int		ft_check(t_data_box *data);
void	ft_move(t_data_box *data, int d, int x, int y);
void	ft_move2(t_data_box *data, int d, int x, int y);
void	ft_replace(t_data_box *data, int x, int y);
void	my_mlx_pixel_put(t_image *image, int x, int y, int color);
void	ft_move_up(t_data_box *data);
void	ft_move_down(t_data_box *data);
void	ft_move_right(t_data_box *data);
void	ft_move_left(t_data_box *data);
int		moves(int keycode, t_data_box *data);
int		init_window(t_data_box *data);
void	display_map(t_data_box *data);
int		free_map(char **map);
void	display_map_2(t_data_box *d, int i, int j);
void	free_mlx(t_data_box *data);
void	images_init(t_data_box *d);
int		newline_check(char	*res);
int		wall_verif(t_data_box *data);
char	**split_res(char *res);

#endif