/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 17:09:04 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/02 18:08:17 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/libft.h"
# include "get_next_line.h"

typedef struct	s_image {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_map
{
	char	**map;
	char	**copy;
	int		x;
	int		y;
	int		pos_player[2];
	int		nb_c;
	int		check;
}				t_map;

typedef struct s_data_box
{
	t_map	*map;
}				t_data_box;

char	**get_map(char *fd_char);
int		check_map(t_data_box *data);
int		nb_lines(t_data_box *data);
int		pars(t_data_box *data, char element);
int		start(t_data_box **data, char *fd);
int		pathfinding(t_data_box *data);
int		ft_check(t_data_box *data);
void	ft_move (t_data_box *data, int d, int x, int y);
void	ft_move2(t_data_box *data, int d, int x, int y);
void	ft_replace(t_data_box *data, int x, int y);

#endif