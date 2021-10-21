/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operation_3.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:40:10 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:28:10 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	c_ra(t_data *data)
{
	rotate(&data->s_a);
	return (1);
}

int	c_rb(t_data *data)
{
	rotate(&data->s_b);
	return (1);
}

int	c_rr(t_data *data)
{
	rotate(&data->s_a);
	rotate(&data->s_b);
	return (1);
}
