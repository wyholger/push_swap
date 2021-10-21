/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_b_and_score.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:33 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 15:59:54 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	init_b(t_data *data)
{
	t_list	*t;
	int		siz;

	siz = data->size;
	t = data->s_a;
	while (siz > 1)
	{
		if (t->x == data->min || t->x == data->max || t->score_a == 1)
		{
			ra(data);
			t = t->next;
		}
		else if (t->x != data->min && t->x != data->max && t->x < data->mid)
		{
			t = t->next;
			pb(data);
		}
		else if (t->x != data->min && t->x != data->max && t->x >= data->mid)
		{
			t = t->next;
			pb(data);
			rb(data);
		}
		siz--;
	}
}

int	score_init_a(t_data *data, int x)
{
	t_list	*l;
	t_list	*r_l;
	int		i;

	l = data->s_a;
	r_l = data->s_a->prev;
	i = 0;
	while (1)
	{
		if (x < l->x && x > l->prev->x)
			return (i);
		if (x < r_l->x && x > r_l->prev->x)
			return ((-1 * i) - 1);
		r_l = r_l->prev;
		l = l->next;
		i++;
	}
}

void	init_unit_score(t_data *data, t_list **l_b, t_list **r_l_b, int i)
{
	(*l_b)->score_a = score_init_a(data, (*l_b)->x);
	(*r_l_b)->score_a = score_init_a(data, (*r_l_b)->x);
	(*l_b)->score_b = i;
	(*r_l_b)->score_b = (i * -1) - 1;
}

void	score_init_b(t_data *data, int i)
{
	t_list	*l_b;
	t_list	*r_l_b;	

	if (data->s_b)
	{
		i = 0;
		l_b = data->s_b;
		r_l_b = l_b->prev;
		while (1)
		{
			init_unit_score(data, &l_b, &r_l_b, i);
			if (l_b == r_l_b || l_b == r_l_b->prev)
				break ;
			l_b = l_b->next;
			r_l_b = r_l_b->prev;
			i++;
		}
		if (l_b == r_l_b)
		{
			l_b->score_a = score_init_a(data, l_b->x);
			l_b->score_b = i;
		}
	}
	else
		return ;
}
