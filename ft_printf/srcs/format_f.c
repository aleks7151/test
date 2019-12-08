/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atote <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 13:54:21 by atote             #+#    #+#             */
/*   Updated: 2019/12/04 18:08:39 by atote            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libftprintf.h"

char	*stepen_of_5(char *res11, char *preres)
{
	res11 = long_arif(preres, preres, '+');
	res11 = long_arif(res11, preres, '+');
	res11 = long_arif(res11, preres, '+');
	res11 = long_arif(res11, preres, '+');
	return (res11);
}

char	**map_of_stepen(void)
{
	int		y;
	char	**res11;

	y = 0;
	res11 = (char **)malloc(sizeof(char *) * 120);
	while (y < 119)
	{
		if (y != 0)
			res11[y] = (char *)malloc(sizeof(char) * 400);
		y++;
	}
	res11[y] = 0;
	y = 0;
	while (y < 119)
	{
		if (y == 0)
		{
			res11[y] = ft_itoa_dr(5);
			res11[y] = get_left_space_for_la(res11[y]);
		}
		else if (y != 0)
			res11[y] = stepen_of_5(res11[y], res11[y - 1]);
		y++;
	}
	return (res11);
}

int		predel_f(t_params *m)
{
	if (m->doubl == -1.0 / 0.0)
	{
		m->cha2 = "-inf";
		m->f_check_zero = 0;
		m->f_check_space = 0;
		return (1);
	}
	if (m->doubl == 1.0 / 0.0)
	{
		m->cha2 = "inf";
		if (m->f_check_plus)
			m->cha2 = "+inf";
		m->f_check_zero = 0;
		return (1);
	}
	if (m->doubl != m->doubl)
	{
		m->cha2 = "nan";
		m->f_check_zero = 0;
		m->f_check_space = 0;
		return (1);
	}
	return (0);
}

int		predel_f1(t_params *m)
{
	if (predel_f(m))
	{
		print_format_str(m);
		return (1);
	}
	if (1.0 / m->doubl == -1.0 / 0.0)
	{
		if (m->f_check_width != 0)
		{
			ft_putchar('-');
			m->f_check_width--;
		}
		m->f_check_minus = 1;
	}
	return (0);
}

void	format_f(char *line, int i, va_list a, int type)
{
	t_params		m;
	long double		doubl1;
	char			**res11;

	m.type = type;
	take_all_params(line, i, &m);
	if (m.f_check_value_precision == 0)
		m.f_check_value_precision = 6;
	if (!ft_check_long_f(line, i))
		m.doubl = va_arg(a, double);
	else
		m.doubl = va_arg(a, long double);
	m.long_long_in = m.doubl;
	if (predel_f1(&m))
		return ;
	doubl1 = m.doubl;
	if (m.long_long_in == 0 && m.doubl > 0)
		doubl1 = doubl1 + 1;
	if (m.long_long_in == 0 && m.doubl < 0)
		doubl1 = doubl1 - 1;
	m.res = get_only_mant(bit_fourth(doubl1, 1), 1, 1);
	vibor_mantiss(doubl1, &m);
	res11 = map_of_stepen();
	print_format_f(&m, get_allres(res11, &m));
}
