/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcros-mo <lcros-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 00:18:29 by lcros-mo          #+#    #+#             */
/*   Updated: 2020/08/06 12:35:42 by lcros-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	u_minus(long int i, t_flags *s)
{
	while (s->precision > ft_intlen(i))
	{
		putchar_prntf('0', s);
		(s->precision)--;
		s->width--;
	}
	s->precision = -1;
	ft_putlongnbr(i, s);
	while (s->width > ft_intlen(i))
	{
		putchar_prntf(' ', s);
		s->width--;
	}
}

void	u_no_minus(long int i, t_flags *s)
{
	char	fill;

	if (s->zero && s->precision == -1)
		fill = '0';
	else
		fill = ' ';
	if (s->precision > ft_intlen(i))
		s->width -= (s->precision - ft_intlen(i));
	while (s->width > ft_intlen(i))
	{
		putchar_prntf(fill, s);
		s->width--;
	}
	while (s->precision > ft_intlen(i))
	{
		putchar_prntf('0', s);
		s->precision--;
	}
	s->precision = -1;
	ft_putlongnbr(i, s);
}

void	print_u(t_flags *s)
{
	long int		i;

	i = va_arg(s->args, unsigned int);
	if (i == 0 && s->precision == 0)
		num_null(s);
	else if (i < 0)
		i += 4294967296;
	else if (s->minus)
		u_minus(i, s);
	else
		u_no_minus(i, s);
}
