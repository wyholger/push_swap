/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:46 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:25:43 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort(t_data *data)
{
	t_list	*push_unit;
	int		i;
	int		step_a;
	int		step_b;

	push_unit = serch_min_score(data, &data->s_b);
	i = 0;
	while (1)
	{
		step_a = push_unit->score_a;
		step_b = push_unit->score_b;
		rotate_logic(data, step_a, step_b);
		pa(data);
		score_init_b(data, 0);
		push_unit = serch_min_score(data, &data->s_b);
		if (!push_unit)
			break ;
		i++;
	}
	rotate_after_sort(data, &data->s_a);
}

void	rotate_logic(t_data *data, int step_a, int step_b)
{
	if (step_a < 0 && step_b < 0)
		down_sicle_a_b(data, &step_a, &step_b);
	if (step_a > 0 && step_b > 0)
		up_sicle_a_b(data, &step_a, &step_b);
	if (step_a < 0)
		down_sicle_a(data, (step_a * -1));
	if (step_a > 0)
		up_sicle_a(data, step_a);
	if (step_b < 0)
		down_sicle_b(data, (step_b * -1));
	if (step_b > 0)
		up_sicle_b(data, step_b);
}

void	rotate_after_sort(t_data *data, t_list **s_a)
{
	t_list	*l;
	t_list	*r_l;
	int		i;

	i = 0;
	l = *s_a;
	r_l = (*s_a)->prev;
	while (1)
	{
		if (l->x == data->min)
		{
			up_sicle_a(data, i);
			break ;
		}
		if (r_l->x == data->min)
		{
			down_sicle_a(data, i + 1);
			break ;
		}
		i++;
		l = l->next;
		r_l = r_l->prev;
	}
}
