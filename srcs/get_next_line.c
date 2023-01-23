/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:49:49 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/17 10:49:54 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	i = -1;
	j = -1;
	if (!s1)
		s1 = ft_calloc(sizeof(char), 1);
	if (!s2)
		return (NULL);
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (s1[++i])
		str[i] = s1[i];
	while (s2[++j])
		str[i + j] = s2[j];
	str[i + j] = '\0';
	if (s1)
		free(s1);
	return (str);
}

char	*ft_delete(char *temp)
{
	int		i;
	int		j;
	char	*str;

	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	str = NULL;
	while (temp[i] && temp[i] != '\n')
		i++;
	if (temp[i])
	{
		str = malloc(sizeof(char) * (ft_strlen(temp) - i + 1));
		if (!str)
			return (NULL);
		if (temp[i] == '\n')
			i++;
		while (temp[i] != '\0')
			str[j++] = temp[i++];
		str[j] = '\0';
	}
	free(temp);
	return (str);
}

char	*ft_res(char *gnl)
{
	char	*res;
	int		i;
	int		j;

	if (!gnl || !*gnl)
		return (NULL);
	i = 0;
	while (gnl[i] && gnl[i] != '\n')
		i++;
	if (gnl[i] == '\n')
		i++;
	res = malloc(sizeof(char) * i + 1);
	if (!res)
		return (NULL);
	j = 0;
	while (j < i)
	{
		res[j] = gnl[j];
		j++;
	}
	res[i] = '\0';
	return (res);
}

char	*ft_write(long len, char *temp, char *gnl, int fd)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	len = read(fd, temp, BUFFER_SIZE);
	if (len < 0)
		return (NULL);
	temp[len] = '\0';
	gnl = ft_gnl_strjoin(gnl, temp);
	return (gnl);
}

char	*get_next_line(int fd)
{
	static char	*gnl;
	char		*temp;
	char		*res;
	long		len;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!temp)
		return (NULL);
	len = 1;
	while (len && (!gnl || (gnl && !ft_strchr_v2(gnl, '\n'))))
	{
		gnl = ft_write(len, temp, gnl, fd);
		if (!gnl || BUFFER_SIZE > (int)ft_strlen(temp))
			break ;
	}
	res = ft_res(gnl);
	gnl = ft_delete(gnl);
	if (temp)
		free(temp);
	return (res);
}
