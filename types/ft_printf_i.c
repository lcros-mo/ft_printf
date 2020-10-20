/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcros-mo <lcros-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 00:18:29 by lcros-mo          #+#    #+#             */
/*   Updated: 2020/08/06 12:35:42 by lcros-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	i_minus(int i, t_flags *s)
{
	if (i < 0)
	{
		putchar_prntf('-', s);
		s->width--;
	}
	while (s->precision > ft_intlen(i))
	{
		putchar_prntf('0', s);
		(s->precision)--;
		s->width--;
	}
	ft_putnbr(i, s);
	while (s->width > ft_intlen(i))
	{
		putchar_prntf(' ', s);
		s->width--;
	}
}

void	i_no_minus_prec(int i, t_flags *s)
{
	if (i < 0 && (!s->zero || s->precision >= 0))
		putchar_prntf('-', s);
	while (s->precision > ft_intlen(i))
	{
		putchar_prntf('0', s);
		s->precision--;
	}
}

void	i_no_minus(int i, t_flags *s)
{
	char	fill;

	if (s->zero && s->precision == -1)
	{
		fill = '0';
		if (i < 0)
			putchar_prntf('-', s);
	}
	else
		fill = ' ';
	if (s->precision > ft_intlen(i))
		s->width -= (s->precision - ft_intlen(i));
	if (i < 0)
		s->width--;
	while (s->width > ft_intlen(i))
	{
		putchar_prntf(fill, s);
		s->width--;
	}
	i_no_minus_prec(i, s);
	ft_putnbr(i, s);
}

void	num_null(t_flags *s)
{
	char	fill;

	if (s->zero && !s->minus)
		fill = '0';
	else
		fill = ' ';
	while (s->width)
	{
		putchar_prntf(fill, s);
		s->width--;
	}
}

void	print_i(t_flags *s)
{
	int		i;

	i = va_arg(s->args, int);
	if (i == 0 && s->precision == 0)
		num_null(s);
	else if (s->minus)
		i_minus(i, s);
	else
		i_no_minus(i, s);
}
