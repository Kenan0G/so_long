/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 18:50:27 by kgezgin           #+#    #+#             */
/*   Updated: 2022/12/27 19:14:38 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5

# endif

char	*get_next_line(int fd);
char	*ft_gnl_strjoin(char *s1, char *s2);
size_t	ft_gnl_strlen(char *str);
void	*ft_gnl_calloc(size_t count, size_t size);
char	*ft_gnl_strchr(char *s, int c);

#endif