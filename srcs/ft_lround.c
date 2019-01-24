/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lround.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:58:01 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 17:12:34 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Round a double, or to the even number when exacltly between the two.
*/

/*
** /!\ UNTESTED /!\
*/

long double			ft_lroundtoeven(long double d, int unit)
{
	double		sign;
	int			digit;
	long int	dtmp;

	sign = (d < 0) ? -1.0 : 1.0;
	d *= sign;
	if (unit < 0)
		dtmp = (d * ft_pow(10, -unit) % 10);
	else
		dtmp = (d / ft_pow(10, unit) % 10);
	dlow = d - (long long int)d;
	digit = (long long int);
	if ((long long int)(d * 10) % 10 < 5)
		return ((long double)((long long int)d + sign));
	d *= sign;
	return (d);
}
