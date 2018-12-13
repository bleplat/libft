/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:55:40 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/13 19:35:14 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>//
#include "libft.h"

static int			double_int_size(long double d)
{
	int s = 0;

	while (d >= 1.0)
	{
		d /= 10.0;
		s++;
	}
	return (ft_max(1, s));
}

static char			pop_dg(long double *d, int digit_loc)
{
	long double	destroyed;
	char		digit;

	printf(" -- d == %Lf\t", *d);
	destroyed = *d / (long double)ft_llpow(10, digit_loc);
	printf(" -- destroyed == %Lf\t", destroyed);
	digit = (char)destroyed;
	printf(" -- digit == %d\n", digit);
	*d -= (long double)digit * (long double)ft_llpow(10, digit_loc);
	return ('0' + digit);
}

static long double	alt_round(long double d, unsigned int precision)
{
	int				digit;
	int				next_digit;

	//if (precision < 0)
	//	return (d);
	digit = ((long long int)(d * ft_llpow(10, precision + 0))) % 10;
	next_digit = ((long long int)(d * ft_llpow(10, precision + 1))) % 10;
	if (next_digit < 5 || (next_digit == 5 && digit % 2))
		return (d);
	else
		d += (1.0 / ft_llpow(10, precision));
	return (d);
}

static int			len_needs(long double d, unsigned int precision)
{
	int	len;

	len = 0;
	if (d < 0)
	{
		len++;
		d *= -1;
	}
	while (d >= 10.0)
	{
		len++;
		d /= 10;
	}
	len += 3 + precision;
	return (len);
}

static void			append_char(char *str, char c)
{
	while (*str != 0)
		str++;
	*str = c;
}

char				*ft_ldtoa(long double d, unsigned int precision)
{
	int				pos;
	long double		sign;
	char			*rst;
	char			c;

	if (d == 1.0 / 0.0)
		return (ft_strdup("inf"));
	if (d == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (d != d)
		return (ft_strdup("nan"));
	sign = (d > 0.0) ? 1.0 : -1.0;
	d *= sign;
	d = alt_round(d, precision);
	if (!(rst = ft_strnew(len_needs(d, precision))))
		return (NULL);
	if (sign == -1.0)
		append_char(rst, '-');
	pos = double_int_size(d) - 1;
	printf(" -- int part size: %d\n", pos + 1);
	while (pos >= 0)
	{
		c = pop_dg(&d, pos);
		append_char(rst, c);
		pos--;
	}
	if (precision == 0)
		return (rst);
	append_char(rst, '.');
	while (precision > 0)
	{
		d *= 10;
		c = pop_dg(&d, 0);
		append_char(rst, c);
		precision--;
	}
	return (rst);
}
