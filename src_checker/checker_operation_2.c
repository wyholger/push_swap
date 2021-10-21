/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_operation_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:40:05 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 15:40:06 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	c_sa(t_data *data)
{
	if (swap(&data->s_a))
		return (1);
	else
		return (0);
}

int	c_sb(t_data *data)
{
	if (swap(&data->s_b))
		return (1);
	else
		return (0);
}

int	c_ss(t_data *data)
{
	if (swap(&data->s_b) || swap(&data->s_a))
		return (1);
	else
		return (0);
}
