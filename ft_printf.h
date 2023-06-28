/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:41:31 by gykoh             #+#    #+#             */
/*   Updated: 2023/06/28 18:37:23 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	ft_check(char c, va_list *args);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(long long n);
int	ft_puthex(unsigned long n, int flag);
int	ft_putaddr(unsigned long n);

#endif
