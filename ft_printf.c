/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:30:42 by gykoh             #+#    #+#             */
/*   Updated: 2023/05/28 18:07:54 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_check(char c, va_list *args)
{
    int len;

    len = 0;
    if (c == 'c')
        len += ft_putchar(va_arg(*args, int));
    else if (c == 's')
        len += ft_putstr(va_arg(*args, char *));
    else if (c == 'd' || c == 'i')
        len += ft_putnbr(va_arg(*args, int));
    else if (c == 'u')
        len += ft_put_unsigned_nbr(va_arg(*args, unsigned int));
    else if (c == 'x')
        len += ft_puthex(va_arg(*args, unsigned int), 0);
    else if (c == 'X')
        len += ft_puthex(va_arg(*args, unsigned int), 1);
    else if (c == 'p')
    {
        len += ft_putstr("0x");
        len += ft_putadr(va_arg(*args, unsigned int));
    }
    else if (c == '%')
        len += ft_putchar('%');
    return (len);
}

int ft_printf(const char *format, ...)
{
    int i;
    int len;
    va_list args;

    i = 0;
    len = 0;
    va_start(args, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            len += ft_check(format[i + 1], &args);
            i++;
        }
        else
            len += write(1, &format[i], 1);
        i++;
    }
    va_end(args);
    return (len);
}