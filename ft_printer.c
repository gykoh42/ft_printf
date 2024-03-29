/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gykoh <gykoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 14:30:46 by gykoh             #+#    #+#             */
/*   Updated: 2023/06/28 19:16:09 by gykoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	len;

	len = write(1, &c, 1);
	return (len);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	if (!str)
		str = "(null)";
	while (*str)
		len += write(1, str++, 1);
	return (len);
}

int	ft_putnbr(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		len += ft_putchar('-');
		n *= -1;
	}
	if (n >= 10)
		len += ft_putnbr(n / 10);
	len += ft_putchar(n % 10 + '0');
	return (len);
}

int	ft_puthex(unsigned long n, int flag)
{
	int		len;
	char	*base;

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

int	ft_putaddr(unsigned long n)
{
	int	len;

	len = 0;
	len += ft_putstr("0x");
	len += ft_puthex(n, 0);
	return (len);
}
