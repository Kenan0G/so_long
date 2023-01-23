/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 13:41:14 by kgezgin           #+#    #+#             */
/*   Updated: 2023/01/13 15:10:04 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*pointer;

	i = 0;
	pointer = (char *)s;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return (&pointer[i]);
		i++;
	}
	if (s[i] == (char)c)
		return (&pointer[i]);
	return (NULL);
}

char	*ft_strchr_v2(char *s, int c)
{
	size_t	i;

	if (!s)
		return (NULL);
	i = -1;
	while (s[++i])
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (NULL);
}