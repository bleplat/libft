/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfuse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 17:51:21 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/04 20:08:06 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "libft.h"

/*
** Fuse *s1 and *s2, returning a pointer to a new string.
** Free parameters depending on LIBFT_FREETASK, except
** when one is NULL, because the other is returned.
** Otherwise *s1 and *s2 may be set to NULL.
** Return NULL on error or if both strings where NULL.
*/

char		*ft_strfuse(char **s1, char **s2, int free_task)
{
	char	*new_str;

	if (*s1 == NULL)
		return (*s2);
	if (*s2 == NULL)
		return (*s1);
	new_str = ft_strjoin(*s1, *s2);
	if (free_task & LIBFT_FREETASK_1ST)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (free_task & LIBFT_FREETASK_2ND)
	{
		free(*s2);
		*s2 = NULL;
	}
	return (new_str);
}
