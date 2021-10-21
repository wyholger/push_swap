/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:00 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:11:38 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sa(t_data *data)
{
	if (swap(&data->s_a))
	{
		ft_putstr_fd("sa\n", 1);
		return (1);
	}
	else
		return (0);
}

int	sb(t_data *data)
{
	if (swap(&data->s_b))
	{
		ft_putstr_fd("sb\n", 1);
		return (1);
	}
	else
		return (0);
}

int	ss(t_data *data)
{
	if (swap(&data->s_b) || swap(&data->s_a))
	{
		ft_putstr_fd("ss\n", 1);
		return (1);
	}
	else
		return (0);
}

int	pa(t_data *data)
{
	if (push(&data->s_b, &data->s_a))
	{
		ft_putstr_fd("pa\n", 1);
		return (1);
	}
	else
		return (0);
}

int	pb(t_data *data)
{
	if (push(&data->s_a, &data->s_b))
	{
		ft_putstr_fd("pb\n", 1);
		return (1);
	}
	else
		return (0);
}
