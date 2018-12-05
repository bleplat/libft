/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 14:44:05 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/05 14:54:14 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "libft.h"

t_llint				ft_random(void)
{
	int			fd;
	t_llint		rst;

	fd = open("/dev/urandom", O_RDONLY);
	if (fd < 0)
		return (0);
	rst = 0;
	read(fd, (char*)(&rst), sizeof(rst));
	close(fd);
	return (rst);
}
