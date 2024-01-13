/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:55:41 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/13 11:56:31 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node {
	int				x;
	int				index;
	int				push_cost;
	int				is_cheapest;
	int				is_above_median;
	struct s_node	*target_node;
	struct s_node	*next;
}				t_node;

//funcs
void	sa(t_node **listA, int print_it);
void	sb(t_node **listB, int print_it);
void	pa(t_node **listA, t_node **listB, int print_it);
void	pb(t_node **listA, t_node **listB, int print_it);
void	ra(t_node **listA, int print_it);

//funcs2.c
void	rb(t_node **listB, int print_it);
void	rr(t_node **listA, t_node **listB, int print_it);
void	rra(t_node **listA, int print_it);
void	rrb(t_node **listB, int print_it);
void	rrr(t_node **listA, t_node **listB, int print_it);

//funcs3.c
void	ss(t_node **listA, t_node **listB, int print_it);

//debug funcs to delete after
void	displayList(t_node *listA, t_node *listB);
void	displayListPushCosts(t_node *listA);

//checks.c
int		check_is_sort(t_node *list);
void	check_errors(int nb_of_arg, char **args, int is_splited);
void	write_error(char **argv, int is_splited);
void	write_error_bonus(char **argv, t_node **list_a,
			t_node **list_b, int is_splited);

//utils.c
int		calculate_length(t_node *list);
int		count_number_of_args(char **args);
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
t_node	*find_biggest(t_node *listA);

//utils2.c
void	free_l_list(t_node **l_list);
t_node	*get_cheapest(t_node *l_list);
t_node	*find_smallest(t_node *l_list);
void	add_end(t_node **to_add, int value);
void	fill_list_a(int argc, char **argv, t_node **list_a);

//utils3.c
void	free_splited_argv(char **argv);

//ft_split.c
char	**ft_split(char const *s, char c);

//sorts.c
void	sort_three(t_node **listA);
void	sort_lists(t_node **listA, t_node **listB);

//sorts2.c
void	first_step_one(t_node **listA, t_node **listB);

//init_utils.c
void	set_values_a(t_node *listA, t_node *listB);
void	set_indexes_and_median(t_node *l_list);
void	set_is_cheapest(t_node *l_list);
void	set_push_costs_a(t_node *listA, t_node *listB);

#endif
