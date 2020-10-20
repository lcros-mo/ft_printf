/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcros-mo <lcros-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 00:18:29 by lcros-mo          #+#    #+#             */
/*   Updated: 2020/08/06 12:35:42 by lcros-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	p_minus(long int p, t_flags *s)
{
	s->precision = 7;
	putstr_prntf("0x", s);
	ft_putnbr_hex(p, s, "0123456789abcdef");
	s->width -= 2;
	while (s->width > ft_intlen_hex(p))
	{
		putchar_prntf(' ', s);
		s->width--;
	}
}

static void	p_no_minus(long int p, t_flags *s)
{
	int	precision;

	precision = s->precision;
	s->width -= 2;
	while (s->width > ft_intlen_hex(p))
	{
		putchar_prntf(' ', s);
		s->width--;
	}
	s->precision = 10;
	putstr_prntf("0x", s);
	while (precision > ft_intlen_hex(p))
	{
		putchar_prntf('0', s);
		precision--;
	}
	ft_putnbr_hex(p, s, "0123456789abcdef");
}

static void	p_null(t_flags *s, char *str, int precision)
{
	char	fill;

	if (s->minus)
	{
		putstr_prntf(str, s);
		while (s->width > ft_strlen(str, precision))
		{
			putchar_prntf(' ', s);
			s->width--;
		}
	}
	else
	{
		if (s->zero)
			fill = '0';
		else
			fill = ' ';
		while (s->width > ft_strlen(str, precision))
		{
			putchar_prntf(' ', s);
			s->width--;
		}
		putstr_prntf(str, s);
	}
}

void		print_p(t_flags *s)
{
	long int	p;
	char		*str;
	int			precision;

	p = (long int)va_arg(s->args, long int);
	if (p == 0 && s->precision == 0)
	{
		str = "0x";
		s->precision = 2;
		precision = s->precision;
		p_null(s, str, precision);
	}
	else if (s->minus)
		p_minus(p, s);
	else
		p_no_minus(p, s);
}
