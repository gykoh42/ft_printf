#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>

int ft_putchar(char c);
int ft_putstr(char *str);
int ft_putnbr(int n);
int ft_put_unsigned_nbr(unsigned int n);
int ft_puthex(unsigned int n, int flag);
int	ft_putadr(unsigned long int nb);

#endif