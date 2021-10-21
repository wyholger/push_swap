/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_no_overflow.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:41:11 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 15:50:45 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	check_atoi_rez(t_data *data, unsigned long int rezult, int single)
{
	if (rezult > 2147483647 && single > 0)
	{
		ft_lstclear(&data->s_a);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	if (rezult > 2147483648 && single < 0)
	{
		ft_lstclear(&data->s_a);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

void	check_valid_arg(t_data *data, const char *str)
{
	if (!str[0])
		return ;
	if (!((str[0] >= '0') && (str[0] <= '9')))
	{
		ft_lstclear(&data->s_a);
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
}

int	atoi_no_overflow(t_data *data, const char *str)
{
	int					i;
	unsigned long int	result;
	int					single;

	i = 0;
	result = 0;
	single = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			single = single * -1;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
		check_atoi_rez(data, result, single);
	}
	check_valid_arg(data, &str[i]);
	return ((int)result * single);
}
