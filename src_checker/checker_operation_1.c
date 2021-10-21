/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operation_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:40:00 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:27:47 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	c_pa(t_data *data)
{
	if (push(&data->s_b, &data->s_a))
		return (1);
	else
		return (0);
}

int	c_pb(t_data *data)
{
	if (push(&data->s_a, &data->s_b))
		return (1);
	else
		return (0);
}

int	c_rra(t_data *data)
{
	r_rotate(&data->s_a);
	return (1);
}

int	c_rrb(t_data *data)
{
	r_rotate(&data->s_b);
	return (1);
}

int	c_rrr(t_data *data)
{
	r_rotate(&data->s_a);
	r_rotate(&data->s_b);
	return (1);
}
