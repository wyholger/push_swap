/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up_cycles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:55 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:26:14 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	up_sicle_b(t_data *data, int i)
{
	while (i > 0)
	{
		rb(data);
		i--;
	}
}

void	up_sicle_a(t_data *data, int i)
{
	while (i > 0)
	{
		ra(data);
		i--;
	}
}

void	up_sicle_a_b(t_data *data, int *step_a, int *step_b)
{
	while (*step_a != 0 && *step_b != 0)
	{
		rr(data);
		*step_a -= 1;
		*step_b -= 1;
	}
}
