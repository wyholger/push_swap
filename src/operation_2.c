/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:04 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:11:55 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	ra(t_data *data)
{
	rotate(&data->s_a);
	ft_putstr_fd("ra\n", 1);
	return (1);
}

int	rb(t_data *data)
{
	rotate(&data->s_b);
	ft_putstr_fd("rb\n", 1);
	return (1);
}

int	rr(t_data *data)
{
	rotate(&data->s_a);
	rotate(&data->s_b);
	ft_putstr_fd("rr\n", 1);
	return (1);
}
