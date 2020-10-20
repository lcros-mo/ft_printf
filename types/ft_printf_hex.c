/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcros-mo <lcros-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 00:18:29 by lcros-mo          #+#    #+#             */
/*   Updated: 2020/08/06 12:35:42 by lcros-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	x_minus(long int i, t_flags *s, char *base)
{
	while (s->precision > ft_intlen_hex(i))
	{
		putchar_prntf('0', s);
		(s->precision)--;
		s->width--;
	}
	ft_putnbr_hex(i, s, base);
	while (s->width > ft_intlen_hex(i))
	{
		putchar_prntf(' ', s);
		s->width--;
	}
}

void	x_no_minus(long int i, t_flags *s, char *base)
{
	char	fill;

	if (s->zero && s->precision == -1)
		fill = '0';
	else
		fill = ' ';
	if (s->precision > ft_intlen_hex(i))
		s->width -= (s->precision - ft_intlen_hex(i));
	while (s->width > ft_intlen_hex(i))
	{
		putchar_prntf(fill, s);
		s->width--;
	}
	while (s->precision > ft_intlen_hex(i))
	{
		putchar_prntf('0', s);
		s->precision--;
	}
	ft_putnbr_hex(i, s, base);
}

void	print_x(t_flags *s, char *format, int it)
{
	long int	i;
	char		*base;

	i = va_arg(s->args, unsigned int);
	if (i == 0 && s->precision == 0)
		num_null(s);
	else
	{
		if (format[it] == 'x')
			base = "0123456789abcdef";
		else
			base = "0123456789ABCDEF";
		if (s->minus)
			x_minus(i, s, base);
		else
			x_no_minus(i, s, base);
	}
}
