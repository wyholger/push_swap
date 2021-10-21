/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:25 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:00:26 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	max_sort_order_init_pre_mid_logic(t_data *data, int order, t_list **l)
{
	if ((*l)->x > order && (*l)->x < data->mid)
	{
		order = (*l)->x;
		(*l)->score_a = 1;
	}
	else
		(*l)->score_a = 0;
	return (order);
}

void	compare_deviation(int *deviation, int *min_deviation, \
	t_list **tmp, t_list **last_mid)
{
	if (mod(*deviation) < mod(*min_deviation))
	{
		*min_deviation = *deviation;
		*last_mid = *tmp;
	}
}

int	mid_search(t_data *data, t_list **a)
{
	t_list	*tmp;
	t_list	*last_mid;
	int		min_deviation;
	int		deviation;
	int		i;

	tmp = *a;
	last_mid = *a;
	deviation = tmp->x - data->mid;
	min_deviation = deviation;
	i = 0;
	while (tmp)
	{
		if (i != 0 && tmp == *a)
			break ;
		deviation = tmp->x - data->mid;
		if (deviation == 0)
			return (tmp->x);
		compare_deviation(&deviation, &min_deviation, &tmp, &last_mid);
		tmp = tmp->next;
		i++;
	}
	return (last_mid->x);
}

void	max_min_mid_init(t_data *data, t_list **a)
{
	t_list	*tmp;
	int		i;

	i = 0;
	tmp = *a;
	data->max = tmp->x;
	data->min = tmp->x;
	while (tmp)
	{
		if (i != 0 && tmp == *a)
			break ;
		if (data->max < tmp->x)
			data->max = tmp->x;
		if (data->min > tmp->x)
			data->min = tmp->x;
		tmp = tmp->next;
		i++;
	}
	data->mid = (data->max + data->min) / 2;
	data->mid = mid_search(data, a);
}
