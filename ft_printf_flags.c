/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcros-mo <lcros-mo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/18 00:18:29 by lcros-mo          #+#    #+#             */
/*   Updated: 2020/08/06 12:35:42 by lcros-mo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags		*initialize(t_flags *s)
{
	s->zero = 0;
	s->minus = 0;
	s->width = 0;
	s->precision = -1;
	return (s);
}

void		handle_flags(char *format, t_flags *s, int *it)
{
	if (format[*it] == '0' && s->zero == 0)
	{
		s->zero = 1;
		(*it)++;
	}
	else if (format[*it] == '-')
	{
		s->minus = 1;
		(*it)++;
	}
	else
		return ;
}

void		handle_precision(char *format, t_flags *s, int *it)
{
	if (format[*it] == '.' && s->precision == -1)
	{
		s->precision = 0;
		(*it)++;
		if (format[*it] == '*')
		{
			s->precision = va_arg(s->args, int);
			(*it)++;
		}
		if ('0' <= format[*it] && format[*it] <= '9')
		{
			s->precision = format[*it] - '0';
			(*it)++;
			while ('0' <= format[*it] && format[*it] <= '9')
			{
				s->precision = s->precision * 10 + format[*it] - '0';
				(*it)++;
			}
		}
	}
	else
		return ;
}

void		handle_width(char *format, t_flags *s, int *it)
{
	if ('0' <= format[*it] && format[*it] <= '9')
	{
		s->width = format[*it] - '0';
		(*it)++;
		while ('0' <= format[*it] && format[*it] <= '9')
		{
			s->width = (s->width * 10) + (format[*it] - '0');
			(*it)++;
		}
	}
	else
		return ;
}
