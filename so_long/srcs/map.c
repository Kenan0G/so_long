/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:54:08 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/02 18:12:31 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_open(char *fd_char)
{
	int	fd;
	int	len;

	len = ft_strlen(fd_char);
	if (fd_char[len - 1] == 'r'
		&& fd_char[len - 2] == 'e'
		&& fd_char[len - 3] == 'b'
		&& fd_char[len - 4] == '.')
	{
		fd = open(fd_char, O_RDONLY);
		if (fd < 0)
			return (-1);
	}
	else
		return (-1);
	return (fd);
}

char	**get_map(char *fd_char)
{
	char	*str;
	char	*res;
	char	**map;
	int		fd;

	fd = ft_open(fd_char);
	if (fd < 0)
		return (NULL);
	res = NULL;
	str = get_next_line(fd);
	if (ft_strlen(str) == 0)
		return (NULL);
	while (str)
	{
		res = ft_gnl_strjoin(res, str);
		free(str);
		str = get_next_line(fd);
	}
	map = ft_split(res, '\n');
	free (res);
	close(fd);
	return (map);
}

int	check_map(t_data_box *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!data->map->map)
		return (0);
	while (i < data->map->y)
	{
		if (((int)ft_strlen(data->map->map[i]) != data->map->x)
			|| data->map->map[i][0] != '1'
			|| data->map->map[i][data->map->x - 1] != '1')
			return (0);
		i++;
	}
	while (data->map->map[0][j])
	{
		if (data->map->map[0][j] != '1' ||
			data->map->map[data->map->y - 1][j] != '1')
			return (0);
		j++;
	}
	if (pars(data, 'P') != 1 || pars(data, 'C') < 1 || pars(data, 'E') != 1)
		return (0);
	return (1);
}

int	nb_lines(t_data_box *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	if (!data->map->map)
		return (0);
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	data->map->nb_c = c;
	return (i);
}

int	pars(t_data_box *data, char element)
{
	int	i;
	int	j;
	int	nb_element;

	i = 0;
	nb_element = 0;
	while (data->map->map[i])
	{
		j = 0;
		while (data->map->map[i][j])
		{
			if (data->map->map[i][j] == element)
			{
				if (element == 'P')
				{
					data->map->pos_player[0] = i;
					data->map->pos_player[1] = j;
				}
				nb_element++;
			}
			j++;
		}
		i++;
	}
	return (nb_element);
}
