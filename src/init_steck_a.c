/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_steck_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:38 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:04:22 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_dub_in_list(t_data *data, t_list **tmp)
{
	t_list	*l;
	int		i;

	i = 0;
	l = *tmp;
	l = l->prev;
	while (l)
	{
		if ((i != 0 && l == *tmp) || (i == 0 && *tmp == (*tmp)->prev))
			break ;
		if ((*tmp)->x == l->x)
		{
			ft_lstclear(&data->s_a);
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		else
		{
			i++;
			l = l->prev;
		}
	}
}

void	init_stack_a(t_data *data, t_list **a, char *argv[], int i)
{
	t_list	*tmp;
	int		flag;
	int		split_flag;

	if (i == 0)
		split_flag = 1;
	else
		split_flag = 0;
	flag = 0;
	tmp = *a;
	while (argv[i])
	{
		ft_lstadd_back(a, ft_lstnew(atoi_no_overflow(data, argv[i])));
		if (flag == 0)
			tmp = *a;
		else
			tmp = tmp->next;
		check_dub_in_list(data, &tmp);
		i++;
		flag = 1;
	}
	data->size = i + split_flag;
}
