/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:23 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:29:35 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	clear_lists(t_data *data, int flag_error)
{
	ft_lstclear(&data->s_a);
	ft_lstclear(&data->s_b);
	if (flag_error == 1)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
}

void	check_sort_checker(t_list **s_a)
{
	t_list	*l;
	int		flag;

	flag = 0;
	l = *s_a;
	while (1)
	{
		if (l == *s_a && flag == 1)
		{
			ft_putstr_fd("OK\n", 1);
			return ;
		}
		if (l->prev->x > l->x && flag != 0)
		{
			ft_putstr_fd("KO\n", 1);
			return ;
		}
		flag = 1;
		l = l->next;
	}
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
