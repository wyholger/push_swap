/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:19 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:58:31 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_sort(t_list **s_a)
{
	t_list	*l;
	int		flag;

	flag = 0;
	l = *s_a;
	while (1)
	{
		if (l == *s_a && flag == 1)
		{
			ft_lstclear(s_a);
			exit (0);
		}
		if (l->prev->x > l->x && flag != 0)
			break ;
		flag = 1;
		l = l->next;
	}
}

void	push_min_b(t_data *data, t_list **l_a)
{
	t_list	*l;
	t_list	*r_l;
	int		i;

	i = 0;
	l = *l_a;
	r_l = l->prev;
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
		l = l->next;
		r_l = r_l->prev;
		i++;
	}
	pb(data);
}

void	rotate_max_down(t_data *data, t_list **l_a)
{
	t_list	*l;
	t_list	*r_l;
	int		i;

	i = 0;
	l = *l_a;
	r_l = l->prev;
	while (1)
	{
		if (l->x == data->max)
		{
			up_sicle_a(data, i + 1);
			break ;
		}
		if (r_l->x == data->max)
		{
			down_sicle_a(data, i);
			break ;
		}
		l = l->next;
		r_l = r_l->prev;
		i++;
	}
	pa(data);
}

int	max_sort_order_init_pre_mid(t_data *data, t_list **s_a)
{
	t_list	*l;
	int		order;
	int		flag;

	flag = 0;
	l = (*s_a)->next;
	order = 0;
	while (1)
	{
		if ((l == *s_a && flag == 1) || l->x == data->max)
			return (order);
		if (l->x < data->mid && flag == 0)
		{
			order = l->x;
			l->score_a = 1;
			flag = 1;
		}
		else if (flag == 1)
			order = max_sort_order_init_pre_mid_logic(data, order, &l);
		l = l->next;
	}
}

void	max_sort_order_init_post_mid(t_data *data, t_list **s_a, int order)
{
	t_list	*l;
	int		flag;

	flag = 0;
	l = (*s_a)->next;
	while (1)
	{
		if ((l == *s_a && flag == 1) || l->x == data->max)
			break ;
		else if (flag == 1)
		{
			if (l->x > order)
			{
				order = l->x;
				l->score_a = 1;
			}
		}
		if (l->x == order && flag == 0)
			flag = 1;
		l = l->next;
	}
}
