/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 10:36:13 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/02 18:28:23 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int start(t_data_box **data, char *fd)
{
	(*data) = malloc(sizeof(t_data_box));
	(*data)->map = malloc(sizeof(t_map));
	(*data)->map->map = get_map(fd);
	if (!(*data)->map->map)
	{
		printf("map = NULL");
		return (0);
	}
	(*data)->map->copy = (*data)->map->map;
	(*data)->map->y = nb_lines(*data);
	(*data)->map->x = ft_strlen((*data)->map->map[0]);
	return (1);
}

int main(int ac, char **av)
{	
	t_data_box	*data;
	if (ac == 2)
	{
		if (!start(&data, av[1]))
			return (0);
		int map = check_map(data);
		int i = 0;
		while (data->map->map[i])
		{
			printf("%s\n", data->map->map[i]);
			i++;
		}
		printf("pos_player x = %d\npos_player y = %d\n", data->map->pos_player[0], data->map->pos_player[1]);
		printf("x = %d\ny = %d\n", data->map->x, data->map->y);
		printf("check_map = %d\n", map);
		if (map)
		{
			int path = pathfinding(data);
			printf("pathfinding = %d\n", path);
		}	
	}
	else
	{
		printf("no map input");
		return (0);
	}
	free(data->map->map);
	free(data->map);
	free(data);
	return (0);
}
