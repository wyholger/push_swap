/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:42:14 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 16:55:17 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	cleaner_char(char **split, int len)
{
	int	i;

	i = 0;
	if (split)
	{
		while (i < len)
		{
			if (split[i])
				free(split[i]);
			i++;
		}
	}
	if (split)
		free(split);
}

char	**check_split(char *argv)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(argv, ' ');
	while (split[i])
		i++;
	if (i > 1)
		return (split);
	cleaner_char(split, i + 1);
	split = NULL;
	return (split);
}

char	**check_argc(int argc, char *argv)
{
	int		i;
	char	**split;

	i = 0;
	if (argc == 2)
	{
		split = check_split(argv);
		if (split)
			return (split);
		while (argv[i])
		{
			if (ft_isdigit(argv[i]))
				i++;
			else
				exit(ft_putstr_fd("Error\n", 2));
		}
		exit (0);
	}
	if (argc < 3)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	split = NULL;
	return (split);
}
