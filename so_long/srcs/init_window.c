/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:08:23 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/18 16:57:44 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_map(t_data_box *d)
{
	int	i;
	int	j;

	i = 0;
	while (d->ma->map[i])
	{
		j = 0;
		while (d->ma->map[i][j])
		{
			display_map_2(d, i, j);
			j++;
		}
		i++;
	}
}

int	set_images(t_data_box *d)
{
	int	a;

	d->i = malloc(sizeof(t_image));
	if (!d->i)
		return (0);
	images_init(d);
	d->i->i_p = mlx_xpm_file_to_image(d->m->m, PLAYER, &a, &a);
	if (!d->i->i_p)
		return (0);
	d->i->i_g = mlx_xpm_file_to_image(d->m->m, GROUND, &a, &a);
	if (!d->i->i_g)
		return (0);
	d->i->i_c = mlx_xpm_file_to_image(d->m->m, COLLECT, &a, &a);
	if (!d->i->i_c)
		return (0);
	d->i->i_w = mlx_xpm_file_to_image(d->m->m, WALL, &a, &a);
	if (!d->i->i_w)
		return (0);
	d->i->i_e = mlx_xpm_file_to_image(d->m->m, EXIT, &a, &a);
	if (!d->i->i_e)
		return (0);
	return (1);
}

int	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free (map[i]);
		i++;
	}
	free(map);
	return (1);
}

void	display_map_2(t_data_box *d, int i, int j)
{
	if (d->ma->map[i][j] == '1')
		mlx_put_image_to_window(d->m->m, d->m->win, d->i->i_w, j * 64, i * 64);
	else if (d->ma->map[i][j] == '0')
		mlx_put_image_to_window(d->m->m, d->m->win, d->i->i_g, j * 64, i * 64);
	else if (d->ma->map[i][j] == 'C')
		mlx_put_image_to_window(d->m->m, d->m->win, d->i->i_c, j * 64, i * 64);
	else if (d->ma->map[i][j] == 'P')
		mlx_put_image_to_window(d->m->m, d->m->win, d->i->i_p, j * 64, i * 64);
	else if (d->ma->map[i][j] == 'E')
		mlx_put_image_to_window(d->m->m, d->m->win, d->i->i_e, j * 64, i * 64);
}

int	init_window(t_data_box *d)
{
	int	x;
	int	y;

	x = d->ma->x * 64;
	y = d->ma->y * 64;
	d->m = malloc(sizeof(t_mlx));
	if (!d->m)
		return (0);
	d->m->m = mlx_init();
	if (!d->m->m)
		exit(EXIT_FAILURE);
	d->m->win = mlx_new_window(d->m->m, x, y, "So_long");
	if (!d->m->win)
		return (free(d->m->m), 0);
	if (!set_images(d))
		return (ft_printf("Error\nImages Not OK\n"), 0);
	display_map(d);
	mlx_hook(d->m->win, 17, 0, mlx_loop_end, d->m->m);
	mlx_key_hook(d->m->win, moves, d);
	mlx_loop(d->m->m);
	return (0);
}
