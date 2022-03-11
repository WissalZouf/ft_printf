/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wzouf <wzouf@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:29:24 by wzouf             #+#    #+#             */
/*   Updated: 2021/12/04 22:52:44 by wzouf            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# define PTAB "0123456789abcdef"
# define XTAB "0123456789ABCDEF"

void	ft_putchar(char c);
void	printhex(unsigned int nb);
void	printp(unsigned long nb);
void	printhexm(unsigned int nb);
void	ft_putnbr(long n);
void	ft_putstr(char *s);
int		ft_printf(const char *s, ...);

int		g_count;

#endif