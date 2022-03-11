/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:24:08 by wzouf             #+#    #+#             */
/*   Updated: 2021/12/04 23:01:01 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		g_count += write(1, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

void	ft_putnbr(long n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -1 * n;
		ft_putchar('-');
	}
	else
		nb = n;
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar(nb % 10 + 48);
}

void	ft_compare(char c, va_list args)
{
	if (c == 'c')
		ft_putchar((char)va_arg(args, char *));
	if (c == 's')
		ft_putstr(va_arg(args, char *));
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	if (c == 'p')
	{
		ft_putstr("0x");
		printp(va_arg(args, unsigned long));
	}
	if (c == 'u')
		ft_putnbr(va_arg(args, unsigned int));
	if (c == 'x')
		printhex(va_arg(args, unsigned int));
	if (c == 'X')
		printhexm(va_arg(args, unsigned int));
	if (c == '%')
		ft_putchar('%');
}

int	ft_printf(const char *s, ...)
{
	char	*str;
	va_list	args;

	str = (char *)s;
	g_count = 0;
	va_start(args, s);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_compare(*str, args);
		}
		else
			ft_putchar(*str);
		str++;
	}
	return (g_count);
}
