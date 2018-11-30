/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 14:43:13 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 16:15:54 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcat(char *s1, const char *s2)
{
	char	*cur;
	int		i2;

	cur = s1;
	while (*cur != '\0')
		cur++;
	i2 = 0;
	while (s2[i2] != '\0')
	{
		*cur = s2[i2];
		cur++;
		i2++;
	}
	*cur = '\0';
	return (s1);
}
