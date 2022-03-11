/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:21:15 by wzouf             #+#    #+#             */
/*   Updated: 2021/12/04 23:01:18 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write (1, &c, 1);
	g_count++;
}

void	printhex(unsigned int nb)
{
	if (nb < 16)
		return (ft_putchar(PTAB[nb % 16]));
	printhex(nb / 16);
	ft_putchar(PTAB[nb % 16]);
}

void	printp(unsigned long nb)
{
	if (nb < 16)
		return (ft_putchar(PTAB[nb % 16]));
	printp(nb / 16);
	ft_putchar(PTAB[nb % 16]);
}

void	printhexm(unsigned int nb)
{
	if (nb < 16)
		return (ft_putchar(XTAB[nb % 16]));
	printhexm(nb / 16);
	ft_putchar(XTAB[nb % 16]);
}
