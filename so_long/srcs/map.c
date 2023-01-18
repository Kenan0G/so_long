/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 17:54:08 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/17 11:32:38 by kgezgin          ###   ########.fr       */
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
	if (!str)
		return (NULL);
	while (str)
	{
		res = ft_gnl_strjoin(res, str);
		free(str);
		str = get_next_line(fd);
	}
	if (newline_check(res) == 0)
		return (free(res), NULL);
	map = split_res(res);
	free (res);
	close(fd);
	return (map);
}

int	check_map(t_data_box *data)
{
	if (!data->ma->map)
		return (ft_printf("Error\nMap Not Valid\n"), 0);
	if (wall_verif(data) == 0)
		return (0);
	if (pars(data, 'P') != 1 || pars(data, 'C') < 1 || pars(data, 'E') != 1)
		return (ft_printf("Error\nItems Not OK\n"), 0);
	return (1);
}

int	nb_lines(t_data_box *data)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	c = 0;
	if (!data->ma->map)
		return (0);
	while (data->ma->map[i])
	{
		j = 0;
		while (data->ma->map[i][j])
		{
			if (data->ma->map[i][j] != 'P' && data->ma->map[i][j] != 'E'
				&& data->ma->map[i][j] != 'C' && data->ma->map[i][j] != '0'
				&& data->ma->map[i][j] != '1')
				data->ma->letter = 0;
			else if (data->ma->map[i][j] == 'C')
				c++;
			j++;
		}
		i++;
	}
	data->ma->nb_c = c;
	return (i);
}

int	pars(t_data_box *data, char element)
{
	int	i;
	int	j;
	int	nb_element;

	i = 0;
	nb_element = 0;
	while (data->ma->map[i])
	{
		j = 0;
		while (data->ma->map[i][j])
		{
			if (data->ma->map[i][j] == element)
			{
				if (element == 'P')
				{
					data->ma->pos_player[0] = i;
					data->ma->pos_player[1] = j;
				}
				nb_element++;
			}
			j++;
		}
		i++;
	}
	return (nb_element);
}
