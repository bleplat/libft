/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strminfield.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:27:21 by bleplat           #+#    #+#             */
/*   Updated: 2019/01/24 17:44:01 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

#include "libft.h"

/*
** Put the given string into another one filled with spaces.
** If the given string is too big then nothing is done.
** Negative width means left aligned.
*/

/*
** /!\ UNTESTED /!\
*/

char		*ft_strminfield(const char *str, int field_width)
{
	char	*new_field;
	int		len;
	int		align;

	align = (field_width > 0) ? 1 : -1;
	field_width = ft_abs(field_width);
	len = ft_strlen(str);
	if (len <= field_width)
		return (ft_strdup(str));
	if (!(new_field = malloc(sizeof(char) * (field_width + 1))))
		return (NULL);
	ft_memset(new_field, ' ', field_width);
	new_field[field_width] = '\0';
	if (align < 0)
		ft_memcpy(new_field, str, len);
	else
		ft_memcpy(new_field + field_width - len, str, len);
	return (new_field);
}
