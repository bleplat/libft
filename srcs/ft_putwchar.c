/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 22:42:25 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/30 18:51:11 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "libft.h"

static int		ft_put4char(char c0, char c1, char c2, char c3)
{
	char	to_put[5];
	int		len;

	to_put[0] = c0;
	to_put[1] = c1;
	to_put[2] = c2;
	to_put[3] = c3;
	to_put[4] = '\0';
	len = ft_strlen(to_put);
	write(1, to_put, ft_max(1, len));
	return (len);
}

/*
** Print an Unicode character and return the count of bytes put.
*/

int				ft_putwchar(unsigned int chr)
{
	if (chr < 0x80)
		return (ft_put4char((char)chr, '\0', '\0', '\0'));
	else if (chr < 0x800)
	{
		return (ft_put4char(((chr >> 6) & 0x1F) | 0xC0,
					((chr >> 0) & 0x3F) | 0x80,
					'\0',
					'\0'));
	}
	else if (chr < 0x10000)
	{
		return (ft_put4char(((chr >> 12) & 0xF) | 0xE0,
					((chr >> 6) & 0x3F) | 0x80,
					((chr >> 0) & 0x3F) | 0x80,
					'\0'));
	}
	else if (chr < 0x110000)
	{
		return (ft_put4char(((chr >> 18) & 0x7) | 0xF0,
					((chr >> 12) & 0x3F) | 0x80,
					((chr >> 6) & 0x3F) | 0x80,
					((chr >> 0) & 0x3F) | 0x80));
	}
	else
		return (0);
}
