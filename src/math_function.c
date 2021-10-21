/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:44 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:05:01 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	mod(int a)
{
	if (a >= 0)
		return (a);
	else
		return (a * -1);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	if (a < b)
		return (b);
	return (1);
}

int	min(int a, int b)
{
	if (a > b)
		return (b);
	if (a < b)
		return (a);
	return (1);
}
