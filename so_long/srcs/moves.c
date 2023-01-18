/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:15:08 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/13 15:45:26 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_up(t_data_box *data)
{
	int		*y;
	int		*x;
	char	temp;

	y = &data->ma->pos_player[0];
	x = &data->ma->pos_player[1];
	if (data->ma->map[*y - 1][*x] == '1')
		return ;
	if (data->ma->map[*y - 1][*x] == 'C')
		data->ma->nb_c -= 1;
	if (data->ma->map[*y - 1][*x] == 'E')
	{
		if (data->ma->nb_c == 0)
			mlx_loop_end(data->m->m);
		return ;
	}
	temp = '0';
	data->ma->pos_player[0] -= 1;
	data->ma->map[*y][*x] = 'P';
	data->ma->map[*y + 1][*x] = temp;
	data->ma->count += 1;
	ft_printf("moves : %d\n", data->ma->count);
	display_map(data);
}

void	ft_move_down(t_data_box *data)
{
	int		*y;
	int		*x;
	char	temp;

	y = &data->ma->pos_player[0];
	x = &data->ma->pos_player[1];
	if (data->ma->map[*y + 1][*x] == '1')
		return ;
	if (data->ma->map[*y + 1][*x] == 'C')
		data->ma->nb_c -= 1;
	if (data->ma->map[*y + 1][*x] == 'E')
	{
		if (data->ma->nb_c == 0)
			mlx_loop_end(data->m->m);
		return ;
	}
	temp = '0';
	data->ma->pos_player[0] += 1;
	data->ma->map[*y][*x] = 'P';
	data->ma->map[*y - 1][*x] = temp;
	data->ma->count += 1;
	ft_printf("moves : %d\n", data->ma->count);
	display_map(data);
}

void	ft_move_right(t_data_box *data)
{
	int		*y;
	int		*x;
	char	temp;

	y = &data->ma->pos_player[0];
	x = &data->ma->pos_player[1];
	if (data->ma->map[*y][*x + 1] == '1')
		return ;
	if (data->ma->map[*y][*x + 1] == 'C')
		data->ma->nb_c -= 1;
	if (data->ma->map[*y][*x + 1] == 'E')
	{
		if (data->ma->nb_c == 0)
			mlx_loop_end(data->m->m);
		return ;
	}
	temp = '0';
	data->ma->pos_player[1] += 1;
	data->ma->map[*y][*x] = 'P';
	data->ma->map[*y][*x - 1] = temp;
	data->ma->count += 1;
	ft_printf("moves : %d\n", data->ma->count);
	display_map(data);
}

void	ft_move_left(t_data_box *data)
{
	int		*y;
	int		*x;

	y = &data->ma->pos_player[0];
	x = &data->ma->pos_player[1];
	if (data->ma->map[*y][*x - 1] == '1')
		return ;
	if (data->ma->map[*y][*x - 1] == 'C')
		data->ma->nb_c -= 1;
	if (data->ma->map[*y][*x - 1] == 'E')
	{
		if (data->ma->nb_c == 0)
			mlx_loop_end(data->m->m);
		return ;
	}
	data->ma->pos_player[1] -= 1;
	data->ma->map[*y][*x] = 'P';
	data->ma->map[*y][*x + 1] = '0';
	data->ma->count += 1;
	ft_printf("moves : %d\n", data->ma->count);
	display_map(data);
}

int	moves(int keycode, t_data_box *data)
{
	if (keycode == 119 || keycode == 65362)
		ft_move_up(data);
	if (keycode == 115 || keycode == 65364)
		ft_move_down(data);
	if (keycode == 100 || keycode == 65363)
		ft_move_right(data);
	if (keycode == 97 || keycode == 65361)
		ft_move_left(data);
	if (keycode == 65307)
	{
		mlx_loop_end(data->m->m);
		return (0);
	}
	return (1);
}
