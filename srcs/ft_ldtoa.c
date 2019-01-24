/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:55:40 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 17:09:36 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	destroyed = *d / (long double)ft_llpow(10, digit_loc);
	digit = (char)destroyed;
	*d -= (long double)digit * (long double)ft_llpow(10, digit_loc);
	return ('0' + digit);
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

static char			*ft_ldtoa_p2(long double d,
								unsigned int precision,
								char *rst)
{
	int				pos;
	char			c;

	pos = double_int_size(d) - 1;
	while (pos >= 0)
	{
		c = pop_dg(&d, pos);
		ft_strputchr(rst, c);
		pos--;
	}
	if (precision == 0)
		return (rst);
	ft_strputchr(rst, '.');
	while (precision > 0)
	{
		d *= 10;
		c = pop_dg(&d, 0);
		ft_strputchr(rst, c);
		precision--;
	}
	return (rst);
}

char				*ft_ldtoa(long double d, unsigned int precision)
{
	long double		sign;
	char			*rst;

	if (d == 1.0 / 0.0)
		return (ft_strdup("inf"));
	if (d == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (d != d)
		return (ft_strdup("nan"));
	sign = (d > 0.0) ? 1.0 : -1.0;
	d *= sign;
	d = ft_alt_round(d, precision);
	if (!(rst = ft_strnew(len_needs(d, precision))))
		return (NULL);
	if (sign == -1.0)
		ft_strputchr(rst, '-');
	return (ft_ldtoa_p2(d, precision, rst));
}
