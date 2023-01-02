/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:40:33 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/02 17:17:07 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void ft_print(t_data_box *data)
// {
// 	int i = 0;
// 	while (data->map->copy[i])
// 	{
// 		printf("%s\n", data->map->copy[i]);
// 		i++;
// 	}
// 	printf("\n");
// }

void	ft_replace(t_data_box *data, int x, int y)
{
	int	d;

	d = 1;
	while (d < 3)
	{
		ft_move(data, d, x, y);
		ft_move2(data, d, x, y);
		d++;
	}
}

void	ft_move(t_data_box *data, int d, int x, int y)
{
	if (d == 1)
	{
		while (data->map->copy[y][x] == 'X')
			x++;
		while (data->map->copy[y][x] != '1')
		{
			data->map->copy[y][x] = 'X';
			x++;
			data->map->check = 1;
		}
	}
	else if (d == 2)
	{
		while (data->map->copy[y][x] == 'X')
			x--;
		while (data->map->copy[y][x] != '1')
		{
			data->map->copy[y][x] = 'X';
			x--;
			data->map->check = 1;
		}
	}
}

void	ft_move2(t_data_box *data, int d, int x, int y)
{
	if (d == 1)
	{
		while (data->map->copy[y][x] == 'X')
			y++;
		while (data->map->copy[y][x] != '1')
		{
			data->map->copy[y][x] = 'X';
			y++;
			data->map->check = 1;
		}
	}
	else if (d == 2)
	{
		while (data->map->copy[y][x] == 'X')
			y--;
		while (data->map->copy[y][x] != '1')
		{
			data->map->copy[y][x] = 'X';
			y--;
			data->map->check = 1;
		}
	}
}

int	ft_check(t_data_box *data)
{
	int	x;
	int	y;
	int	e;
	int	c;

	y = 0;
	e = 0;
	c = 0;
	while (data->map->copy[y])
	{
		x = 0;
		while (data->map->copy[y][x])
		{
			if (data->map->copy[y][x] == 'E')
				e++;
			if (data->map->copy[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (e == 0 && c == 0)
		return (1);
	return (0);
}

int	pathfinding(t_data_box *data)
{
	int	y;
	int	x;

	data->map->check = 1;
	data->map->copy[data->map->pos_player[0]][data->map->pos_player[1]] = 'X';
	while (data->map->check == 1)
	{
		data->map->check = 0;
		y = 0;
		while (data->map->copy[y])
		{
			x = 0;
			while (data->map->copy[y][x])
			{
				if (data->map->copy[y][x] == 'X')
					ft_replace(data, x, y);
				x++;
			}
			y++;
		}
	}
	return (ft_check(data));
}
