/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bleplat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 17:53:32 by bleplat           #+#    #+#             */
/*   Updated: 2018/12/08 18:52:15 by bleplat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

typedef struct s_array		t_array;
struct						s_array
{
	void		*items;
	int			item_size;
	int			item_count;
	int			item_capacity;
};

t_array						*ft_array_new(int item_size, int item_capacity);
void						ft_array_del(t_array **a);
int							ft_array_reserve(t_array *a, int item_capacity);
void						*ft_array_newitem(t_array *a);
int							ft_array_shrink(t_array *a);
void						*ft_array_at(t_array *a, int index);
void						ft_array_clear(t_array *a);
int							ft_array_reset(t_array *a, int item_count);

#endif
