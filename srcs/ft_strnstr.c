/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 19:06:23 by bleplat           #+#    #+#             */
/*   Updated: 2018/11/13 16:42:47 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		i;
	size_t		i_need;

	if (*needle == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0' && i < len)
	{
		i_need = 0;
		while (haystack[i + i_need] == needle[i_need] && (i + i_need) < len)
		{
			if (needle[i_need + 1] == '\0')
				return ((char *)(haystack + i));
			i_need++;
		}
		i++;
	}
	return (NULL);
}
