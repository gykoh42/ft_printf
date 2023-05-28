/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:30:46 by gykoh             #+#    #+#             */
/*   Updated: 2023/05/28 18:08:36 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_putchar(char c)
{
    int len;

    len = write(1, &c, 1);
    return (len);
}

int ft_putstr(char *str)
{
    int len;

    len = 0;
    if (!str)
        str = "(null)";
    while (*str)
        len += write(1, str++, 1);
    return (len);
}

int ft_putnbr(int n)
{
    int len;
    long long nb;

    len = 0;
    nb = n;
    if (nb < 0)
    {
        len += ft_putchar('-');
        nb *= -1;
    }
    if (nb >= 10)
        len += ft_putnbr(nb / 10);
    len += ft_putchar(nb % 10 + '0');
    return (len);
}

int ft_put_unsigned_nbr(unsigned int n)
{
    int len;

    len = 0;
    if (n >= 10)
        len += ft_put_unsigned_nbr(n / 10);
    len += ft_putchar(n % 10 + '0');
    return (len);
}

int ft_puthex(unsigned int n, int flag)
{
    int len;
    char *base;

    len = 0;
    if (flag == 0)
        base = "0123456789abcdef";
    if (flag == 1)
        base = "0123456789ABCDEF";
    if (n >= 16)
        len += ft_puthex((n / 16), flag);
    len += ft_putchar(base[n % 16]);
    return (len);
}

int	ft_putadr(unsigned long int nb)
{
	int	len;

	len = 0;
	if (nb >= 16)
	{
		len += ft_putadr(nb / 16);
		len += ft_putadr(nb % 16);
	}
	if (nb < 16)
	{
		if (nb < 10)
			len += ft_putchar(nb + 48);
		else
			len += ft_putchar(nb + 87);
	}
	return (len);
}