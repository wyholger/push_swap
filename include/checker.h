/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 15:38:02 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:33:02 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include "../libft/libft.h"

typedef struct s_data
{
	t_list	*s_a;
	t_list	*s_b;
	int		max;
	int		min;
	int		mid;
	int		size;
}				t_data;
char	**check_argc(int argc, char *argv);
char	**check_split(char *argv);
void	cleaner_char(char **split, int len);
int		atoi_no_overflow(t_data *data, const char *str);
void	check_valid_arg(t_data *data, const char *str);
void	check_atoi_rez(t_data *data, unsigned long int rezult, int single);
void	init_stack_a(t_data *data, t_list **a, char *argv[], int i);
void	check_dub_in_list(t_data *data, t_list **tmp);
void	init_null_data(t_data *data);
int		swap(t_list **l);
int		rotate(t_list **l);
int		r_rotate(t_list **l);
int		push(t_list **src, t_list **dst);
void	push_logic(t_list **src, t_list **dst);
void	push_logic_if_no_dst(t_list **src, t_list **dst);
int		c_rrr(t_data *data);
int		c_rrb(t_data *data);
int		c_rra(t_data *data);
int		c_pb(t_data *data);
int		c_pa(t_data *data);
int		c_sa(t_data *data);
int		c_sb(t_data *data);
int		c_ss(t_data *data);
int		c_ra(t_data *data);
int		c_rb(t_data *data);
int		c_rr(t_data *data);
int		check_pre_sort_checker(t_list **s_a);
int		start_logic(t_data *data, int argc, char *argv[]);
void	clear_lists(t_data *data, int flag_error);
void	check_sort_checker(t_list **s_a);
void	error(void);
int		ft_action_processing(t_data *data, char *line);
#endif
