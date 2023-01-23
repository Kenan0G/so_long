/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:46:30 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/17 11:32:19 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/so_long.h"

void	images_init(t_data_box *d)
{
	d->i->i_p = NULL;
	d->i->i_c = NULL;
	d->i->i_e = NULL;
	d->i->i_w = NULL;
	d->i->i_g = NULL;
}

int	newline_check(char	*res)
{
	int	i;

	i = 0;
	while (res[i] != '\0')
	{
		if (res[0] == '\n' || (res[i] == '\n' && res[i + 1] == '\n'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	wall_verif(t_data_box *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->ma->y)
	{
		if (((int)ft_strlen(data->ma->map[i]) != data->ma->x)
			|| data->ma->map[i][0] != '1'
			|| data->ma->map[i][data->ma->x - 1] != '1')
			return (ft_printf("Error\nMap Not OK\n"), 0);
		i++;
	}
	while (data->ma->map[0][j])
	{
		if (data->ma->map[0][j] != '1' ||
			data->ma->map[data->ma->y - 1][j] != '1')
			return (ft_printf("Error\nMap Not Surrounded By Walls\n"), 0);
		j++;
	}
	return (1);
}

char	**split_res(char *res)
{
	if (res)
		return (ft_split(res, '\n'));
	return (NULL);
}
