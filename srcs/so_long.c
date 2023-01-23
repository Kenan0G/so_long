/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:36:13 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/17 22:38:39 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free(t_data_box *data)
{
	if (data->ma && data->ma->map)
		free_map(data->ma->map);
	if (data->ma && data->ma->copy)
		free_map(data->ma->copy);
	if (data->ma)
		free (data->ma);
	free (data);
}

void	free_mlx(t_data_box *data)
{
	if (data->i->i_c)
		mlx_destroy_image(data->m->m, data->i->i_c);
	if (data->i->i_p)
		mlx_destroy_image(data->m->m, data->i->i_p);
	if (data->i->i_w)
		mlx_destroy_image(data->m->m, data->i->i_w);
	if (data->i->i_g)
		mlx_destroy_image(data->m->m, data->i->i_g);
	if (data->i->i_e)
		mlx_destroy_image(data->m->m, data->i->i_e);
	mlx_clear_window(data->m->m, data->m->win);
	mlx_destroy_window(data->m->m, data->m->win);
	mlx_destroy_display(data->m->m);
	free (data->m->m);
	free (data->m);
	free (data->i);
}

int	pathfinding(t_data_box *data)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	data->ma->check = 1;
	data->ma->copy[data->ma->pos_player[0]][data->ma->pos_player[1]] = 'X';
	while (data->ma->check == 1)
	{
		data->ma->check = 0;
		y = 0;
		while (data->ma->copy[y])
		{
			x = 0;
			while (data->ma->copy[y][x])
			{
				if (data->ma->copy[y][x] == 'X')
					ft_replace(data, x, y);
				x++;
			}
			y++;
		}
	}
	return (ft_check(data));
}

int	start(t_data_box **data, char *fd)
{
	(*data) = malloc(sizeof(t_data_box));
	if (!(*data))
		return (ft_printf("Error\nMalloc echoue\n"), 1);
	(*data)->ma = malloc(sizeof(t_map));
	if (!(*data)->ma)
		return (ft_printf("Error\nMalloc echoue\n"), 1);
	(*data)->ma->map = get_map(fd);
	(*data)->ma->copy = NULL;
	if (!(*data)->ma->map)
	{
		ft_printf("Error\nInvalid Map\n");
		return (1);
	}
	(*data)->ma->copy = get_map(fd);
	(*data)->ma->letter = 1;
	(*data)->ma->y = nb_lines(*data);
	if ((*data)->ma->letter == 0)
		return (ft_printf("Error\nNot Allowed Character\n"), 1);
	(*data)->ma->x = ft_strlen((*data)->ma->map[0]);
	(*data)->ma->count = 0;
	(*data)->i = NULL;
	(*data)->m = NULL;
	return (0);
}

int	main(int ac, char **av, char **envp)
{
	t_data_box	*data;

	if (!*envp)
		return (ft_printf("Error\nNo Environment\n"), 0);
	if (ac != 2)
		return (ft_printf("Error\nNo Map Input\n"), 0);
	if (start(&data, av[1]))
		return (ft_free(data), 0);
	if (!check_map(data))
		return (ft_free(data), 0);
	if (!pathfinding(data))
	{
		ft_printf("Error\nNo Path Possible\n");
		return (ft_free(data), 0);
	}
	init_window(data);
	free_mlx(data);
	ft_free(data);
	return (0);
}
