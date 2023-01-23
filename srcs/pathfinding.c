/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:40:33 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/12 11:41:33 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
		while (data->ma->copy[y][x] == 'X')
			x++;
		while (data->ma->copy[y][x] != '1' && data->ma->copy[y][x] != 'E')
		{
			data->ma->copy[y][x] = 'X';
			x++;
			data->ma->check = 1;
		}
	}
	else if (d == 2)
	{
		while (data->ma->copy[y][x] == 'X')
			x--;
		while (data->ma->copy[y][x] != '1' && data->ma->copy[y][x] != 'E')
		{
			data->ma->copy[y][x] = 'X';
			x--;
			data->ma->check = 1;
		}
	}
}

void	ft_move2(t_data_box *data, int d, int x, int y)
{
	if (d == 1)
	{
		while (data->ma->copy[y][x] == 'X')
			y++;
		while (data->ma->copy[y][x] != '1' && data->ma->copy[y][x] != 'E')
		{
			data->ma->copy[y][x] = 'X';
			y++;
			data->ma->check = 1;
		}
	}
	else if (d == 2)
	{
		while (data->ma->copy[y][x] == 'X')
			y--;
		while (data->ma->copy[y][x] != '1' && data->ma->copy[y][x] != 'E')
		{
			data->ma->copy[y][x] = 'X';
			y--;
			data->ma->check = 1;
		}
	}
}

int	check_exit(t_data_box *data, int y, int x)
{
	if (data->ma->map[y + 1][x] == 'X' || data->ma->map[y - 1][x] == 'X'
		|| data->ma->map[y][x + 1] == 'X'
		|| data->ma->map[y][x - 1] == 'X')
		return (1);
	return (0);
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
	while (data->ma->copy[y])
	{
		x = 0;
		while (data->ma->copy[y][x])
		{
			if (data->ma->copy[y][x] == 'E')
				e = check_exit(data, y, x);
			if (data->ma->copy[y][x] == 'C')
				c++;
			x++;
		}
		y++;
	}
	if (e == 0 && c == 0)
		return (1);
	return (0);
}
