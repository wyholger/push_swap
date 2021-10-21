/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:39:54 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:30:33 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	start_logic(t_data *data, int argc, char *argv[])
{
	char	**split;

	split = check_argc(argc, argv[1]);
	init_null_data(data);
	if (split)
	{
		init_stack_a(data, &data->s_a, split, 0);
		cleaner_char(split, data->size);
	}
	else
		init_stack_a(data, &data->s_a, argv, 1);
	return (check_pre_sort_checker(&data->s_a));
}

int	check_pre_sort_checker(t_list **s_a)
{
	t_list	*l;
	int		flag;

	flag = 0;
	l = *s_a;
	while (1)
	{
		if (l == *s_a && flag == 1)
			return (1);
		if (l->prev->x > l->x && flag != 0)
			return (0);
		flag = 1;
		l = l->next;
	}
}
