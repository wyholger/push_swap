/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_logic.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:32 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:04:47 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	score_a_b_logic(t_list **l)
{
	t_list	*t;

	t = *l;
	if (t->score_a > 0 && t->score_b > 0)
	{
		if (t->score_a != t->score_b)
			return ((max(t->score_a, t->score_b) \
			- min(t->score_a, t->score_b)) + min(t->score_a, t->score_b));
		else
			return (t->score_a);
	}
	if (t->score_a < 0 && t->score_b < 0)
	{
		if (t->score_a != t->score_b)
			return ((max(mod(t->score_a), mod(t->score_b)) \
			- min(mod(t->score_a), mod(t->score_b))) \
			+ min(mod(t->score_a), mod(t->score_b)));
		else
			return (mod(t->score_a));
	}
	if ((t->score_a >= 0 && t->score_b <= 0) \
	|| (t->score_a <= 0 && t->score_b >= 0))
		return (mod(t->score_a) + mod(t->score_b));
	return (1);
}

t_list	**min_score_logic(t_list **tmp, t_list **min_score_unit, \
int min_score, t_list **l)
{
	int		flag;
	int		now_score;

	flag = 0;
	while (1)
	{
		if (flag == 1 && *tmp == *l)
			break ;
		now_score = score_a_b_logic(tmp);
		if (now_score == min_score)
		{
			if (mod((*tmp)->score_a) < mod((*min_score_unit)->score_a))
				*min_score_unit = *tmp;
		}
		if (now_score < min_score)
		{
			min_score = now_score;
			*min_score_unit = *tmp;
		}
		if (flag == 0)
			flag = 1;
		(*tmp) = (*tmp)->next;
	}
	return (min_score_unit);
}

t_list	*serch_min_score(t_data *data, t_list **l)
{
	t_list	*tmp;
	t_list	*min_score_unit;
	int		min_score;

	tmp = *l;
	min_score = data->size * 2;
	min_score_unit = tmp;
	if (*l)
	{
		min_score_unit = *min_score_logic(&tmp, &min_score_unit, min_score, l);
		return (min_score_unit);
	}
	else
	{
		tmp = NULL;
		return (tmp);
	}
}
