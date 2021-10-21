/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:50 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:10:14 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	up_or_down_for_5(t_data *data, int i, int up_or_down)
{
	if (up_or_down == 0)
	{
		up_sicle_a(data, i);
	}
	if (up_or_down == 1)
	{
		down_sicle_a(data, i + 1);
	}
	return (1);
}

void	push_unit_for_5(t_data *data, t_list **s_a)
{
	t_list	*l;
	t_list	*r_l;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	l = *s_a;
	r_l = l->prev;
	while (1)
	{
		if (l->x != data->max && l->x != data->min)
			flag = up_or_down_for_5(data, i, 0);
		else if (r_l->x != data->max && r_l->x != data->min)
			flag = up_or_down_for_5(data, i, 1);
		if (flag > 0)
			break ;
		l = l->next;
		r_l = r_l->prev;
		i++;
	}
	pb(data);
}
