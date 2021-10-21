/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:39:42 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:29:01 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

int	ft_action_processing(t_data *data, char *line)
{
	if (ft_strncmp(line, "sa", ft_strlen(line)) == 0)
		c_sa(data);
	else if (ft_strncmp(line, "sb", ft_strlen(line)) == 0)
		c_sb(data);
	else if (ft_strncmp(line, "ss", ft_strlen(line)) == 0)
		c_ss(data);
	else if (ft_strncmp(line, "pa", ft_strlen(line)) == 0)
		c_pa(data);
	else if (ft_strncmp(line, "pb", ft_strlen(line)) == 0)
		c_pb(data);
	else if (ft_strncmp(line, "ra", ft_strlen(line)) == 0)
		c_ra(data);
	else if (ft_strncmp(line, "rb", ft_strlen(line)) == 0)
		c_rb(data);
	else if (ft_strncmp(line, "rr", ft_strlen(line)) == 0)
		c_rr(data);
	else if (ft_strncmp(line, "rra", ft_strlen(line)) == 0)
		c_rra(data);
	else if (ft_strncmp(line, "rrb", ft_strlen(line)) == 0)
		c_rrb(data);
	else if (ft_strncmp(line, "rrr", ft_strlen(line)) == 0)
		c_rrr(data);
	else
		return (0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	char	*line;
	int		flag_err;
	int		flag_sort;

	flag_sort = start_logic(&data, argc, argv);
	line = NULL;
	while (get_next_line(0, &line))
	{
		if (flag_sort == 1 && line[0] != 0)
		{
			free(line);
			ft_putstr_fd("KO\n", 1);
			ft_lstclear(&data.s_a);
			return (0);
		}
		flag_err = ft_action_processing(&data, line);
		free(line);
		line = NULL;
		if (flag_err == 0)
			clear_lists(&data, 1);
	}
	free(line);
	check_sort_checker(&data.s_a);
	clear_lists(&data, 0);
}
