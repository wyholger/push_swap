/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:55 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:11:13 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_2(t_data *data, t_list **s_a, int exit_flag)
{
	if ((*s_a)->x > (*s_a)->next->x)
		sa(data);
	if (exit_flag == 1)
	{
		ft_lstclear(s_a);
		exit (0);
	}
}

void	sort_3(t_data *data, t_list **s_a, int exit_flag)
{
	if ((*s_a)->x == data->max)
		ra(data);
	if ((*s_a)->x == data->mid)
	{
		if ((*s_a)->next->x == data->max)
			rra(data);
		else
			sa(data);
		if (exit_flag == 1)
			exit (ft_lstclear(s_a));
		else
			return ;
	}
	if ((*s_a)->next->x == data->max)
	{
		rra(data);
		sa(data);
	}
	if (exit_flag == 1)
		exit (ft_lstclear(s_a));
}

void	sort_4(t_data *data, t_list **s_a, int exit_flag)
{
	push_unit_for_5(data, &data->s_a);
	max_min_mid_init(data, s_a);
	sort_3(data, s_a, 0);
	score_init_b(data, 0);
	sort(data);
	if (exit_flag == 1)
		exit (ft_lstclear(s_a));
}

void	sort_5(t_data *data, t_list **s_a, int exit_flag)
{
	push_unit_for_5(data, &data->s_a);
	push_unit_for_5(data, &data->s_a);
	max_min_mid_init(data, s_a);
	sort_3(data, s_a, 0);
	if (data->s_b->x < data->s_b->next->x)
		sb(data);
	score_init_b(data, 0);
	sort(data);
	if (exit_flag == 1)
		exit (ft_lstclear(s_a));
}
