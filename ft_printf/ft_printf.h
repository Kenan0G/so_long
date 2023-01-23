/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:51:42 by kgezgin           #+#    #+#             */
/*   Updated: 2022/11/28 19:11:37 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

typedef struct s_lenght
{
	int	len;
	int	widht;
}	t_lenght;

int				ft_printf(const char *format, ...);
const char		*ft_checkargs(va_list arg, const char *format, t_lenght *lst);
const char		*ft_print(const char *format, t_lenght *lst);
int				ft_intlen(int n);
void			ft_put_uint(unsigned int n, t_lenght *lst);
unsigned int	ft_printhexa(unsigned long p, int n);
char			*ft_toupper_hexa(char *s);
void			ft_arg_1(const char *format, va_list arg, t_lenght *lst);
void			ft_arg_2(const char *format, va_list arg, t_lenght *lst);
void			ft_arg_4(const char *format, va_list arg, t_lenght *lst);
void			ft_arg_5(va_list arg, t_lenght *lst);

#endif