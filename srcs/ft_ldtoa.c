/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 13:55:40 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/13 17:07:05 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long double	alt_round(long double d, unsigned int precision)
{
	int				digit;
	int				next_digit;
	long double		add;

	if (precision < 0)
		return (d);
	digit = ((long long int)(d * ft_pow(10, precision + 0))) % 10;
	digit = ((long long int)(d * ft_pow(10, precision + 1))) % 10;
	if (next_digit < 5 || (next_digit == 5 && digit % 2))
		d -= ((long double)digit / ft_pow(10, precision + 1));
	else
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

char				*ft_ldtoa(long double d, int precision)
{
	long double		sign;

	if (d == 1.0 / 0.0)
		return (ft_strdup("inf"));
	if (d == -1.0 / 0.0)
		return (ft_strdup("-inf"));
	if (d != d)
		return (ft_strdup("nan"));
	sign = (d > 0.0) ? 1.0 : -1.0;
	d *= sign;
	d = alt_round;



}
