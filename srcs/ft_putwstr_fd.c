/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 13:43:20 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/01 14:11:38 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_putwstr_fd(const int *str, int fd)
{
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	while (str[i] != 0)
	{
		sum += ft_putwchar_fd(str[i], fd);
		i++;
	}
	return (sum);
}
