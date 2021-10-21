/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundamental_operation_1.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:24 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 15:52:12 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	swap(t_list **l)
{
	int	tmp;

	if (*l && *l != (*l)->next)
	{
		tmp = (*l)->x;
		(*l)->x = (*l)->next->x;
		(*l)->next->x = tmp;
		return (1);
	}
	return (0);
}

int	rotate(t_list **l)
{
	if (*l && *l != (*l)->next)
	{
		*l = (*l)->next;
		return (1);
	}
	else
		return (0);
}

int	r_rotate(t_list **l)
{
	if (*l && *l != (*l)->next)
	{
		*l = (*l)->prev;
		return (1);
	}
	else
		return (0);
}
