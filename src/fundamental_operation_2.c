/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fundamental_operation_2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:29 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 15:53:45 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_logic_if_no_dst(t_list **src, t_list **dst)
{
	t_list	*t_s;
	t_list	*tmp;

	t_s = *src;
	tmp = t_s->next;
	t_s->prev->next = t_s->next;
	t_s->next->prev = t_s->prev;
	ft_lstadd_back(dst, t_s);
	*src = tmp;
}

void	push_logic(t_list **src, t_list **dst)
{
	t_list	*t_s;
	t_list	*t_d;
	t_list	*tmp;

	t_s = *src;
	t_d = *dst;
	if (*dst)
	{
		tmp = t_s->next;
		t_s->prev->next = t_s->next;
		t_s->next->prev = t_s->prev;
		t_s->prev = t_d->prev;
		t_s->next = t_d;
		t_d->prev->next = t_s;
		t_d->prev = t_s;
		*src = tmp;
		*dst = t_s;
	}
	else
		push_logic_if_no_dst(src, dst);
}

int	push(t_list **src, t_list **dst)
{
	t_list	*t_s;
	t_list	*t_d;

	t_s = *src;
	t_d = *dst;
	if (*src && (*src)->next != *src)
	{
		push_logic(src, dst);
		return (1);
	}
	else if ((*src)->next == *src && (*src)->prev == *src)
	{
		t_s->prev = t_d->prev;
		t_s->next = t_d;
		t_d->prev->next = t_s;
		t_d->prev = t_s;
		*src = NULL;
		*dst = t_s;
		return (1);
	}
	return (0);
}
