/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wyholger <wyholger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 18:21:28 by wyholger          #+#    #+#             */
/*   Updated: 2021/10/18 17:34:00 by wyholger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
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
int		mod(int a);
int		max(int a, int b);
int		min(int a, int b);
int		pb(t_data *data);
int		pa(t_data *data);
int		ss(t_data *data);
int		sb(t_data *data);
int		sa(t_data *data);
int		rr(t_data *data);
int		rb(t_data *data);
int		ra(t_data *data);
int		rrr(t_data *data);
int		rrb(t_data *data);
int		rra(t_data *data);
void	sort_2(t_data *data, t_list **s_a, int exit_flag);
void	sort_3(t_data *data, t_list **s_a, int exit_flag);
void	sort_4(t_data *data, t_list **s_a, int exit_flag);
void	sort_5(t_data *data, t_list **s_a, int exit_flag);
void	push_unit_for_5(t_data *data, t_list **s_a);
int		up_or_down_for_5(t_data *data, int i, int up_or_down);
void	max_sort_order_init_post_mid(t_data *data, t_list **s_a, int order);
int		max_sort_order_init_pre_mid(t_data *data, t_list **s_a);
int		max_sort_order_init_pre_mid_logic(t_data *data, int order, t_list **l);
void	compare_deviation(int *deviation, int *min_deviation, \
t_list **tmp, t_list	**last_mid);
int		mid_search(t_data *data, t_list **a);
void	max_min_mid_init(t_data *data, t_list **a);
void	rotate_max_down(t_data *data, t_list **l_a);
void	push_min_b(t_data *data, t_list **l_a);
void	check_sort(t_list **s_a);
void	score_init_b(t_data *data, int i);
void	init_unit_score(t_data *data, t_list **l_b, t_list **r_l_b, int i);
int		score_init_a(t_data *data, int x);
void	init_b(t_data *data);
int		score_a_b_logic(t_list **l);
t_list	**min_score_logic(t_list **tmp, t_list **min_score_unit, \
int min_score, t_list **l);
t_list	*serch_min_score(t_data *data, t_list **l);
void	sort(t_data *data);
void	rotate_after_sort(t_data *data, t_list **s_a);
void	rotate_logic(t_data *data, int step_a, int step_b);
void	up_sicle_a_b(t_data *data, int *step_a, int *step_b);
void	up_sicle_a(t_data *data, int i);
void	up_sicle_b(t_data *data, int i);
void	down_sicle_a_b(t_data *data, int *step_a, int *step_b);
void	down_sicle_a(t_data *data, int i);
void	down_sicle_b(t_data *data, int i);
void	push_swap(t_data *data);
#endif