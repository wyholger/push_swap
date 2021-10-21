/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:10 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:12:19 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	rra(t_data *data)
{
	r_rotate(&data->s_a);
	ft_putstr_fd("rra\n", 1);
	return (1);
}

int	rrb(t_data *data)
{
	r_rotate(&data->s_b);
	ft_putstr_fd("rrb\n", 1);
	return (1);
}

int	rrr(t_data *data)
{
	r_rotate(&data->s_a);
	r_rotate(&data->s_b);
	ft_putstr_fd("rrr\n", 1);
	return (1);
}
