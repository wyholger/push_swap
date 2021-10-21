/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down_cycles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:18 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 15:51:13 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	down_sicle_a(t_data *data, int i)
{
	while (i > 0)
	{
		rra(data);
		i--;
	}
}

void	down_sicle_b(t_data *data, int i)
{
	while (i > 0)
	{
		rrb(data);
		i--;
	}
}

void	down_sicle_a_b(t_data *data, int *step_a, int *step_b)
{
	while (*step_a != 0 && *step_b != 0)
	{
		rrr(data);
		*step_a += 1;
		*step_b += 1;
	}
}
