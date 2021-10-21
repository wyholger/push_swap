/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 18:59:44 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:01:21 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;
	char	**split;

	split = check_argc(argc, argv[1]);
	init_null_data(&data);
	if (split)
	{
		init_stack_a(&data, &data.s_a, split, 0);
		cleaner_char(split, data.size);
	}
	else
		init_stack_a(&data, &data.s_a, argv, 1);
	push_swap(&data);
	ft_lstclear(&data.s_a);
}

void	push_swap(t_data *data)
{
	if (data->size == 3)
		sort_2(data, &data->s_a, 1);
	check_sort(&data->s_a);
	max_min_mid_init(data, &data->s_a);
	if (data->size == 4)
		sort_3(data, &data->s_a, 1);
	if (data->size == 5)
		sort_4(data, &data->s_a, 1);
	if (data->size == 6)
		sort_5(data, &data->s_a, 1);
	push_min_b(data, &data->s_a);
	rotate_max_down(data, &data->s_a);
	max_sort_order_init_post_mid(data, &data->s_a, \
	max_sort_order_init_pre_mid(data, &data->s_a));
	init_b(data);
	score_init_b(data, 0);
	sort(data);
}
