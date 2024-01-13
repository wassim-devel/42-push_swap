/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 12:48:05 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/13 11:19:53 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/push_swap.h"

void	do_the_sorting(t_node *list_a, t_node *list_b)
{
	if (!check_is_sort(list_a))
	{
		if (calculate_length(list_a) == 2)
			sa(&list_a, 1);
		else if (calculate_length(list_a) == 3)
			sort_three(&list_a);
		else
			sort_lists(&list_a, &list_b);
	}
	free_l_list(&list_a);
}

int	main(int argc, char **argv)
{
	t_node	*list_a;
	t_node	*list_b;
	int		is_splited;

	is_splited = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		is_splited = 1;
	}
	else
		argv = &argv[1];
	check_errors(count_number_of_args(argv), argv, is_splited);
	list_a = NULL;
	list_b = NULL;
	fill_list_a(count_number_of_args(argv), argv, &list_a);
	do_the_sorting(list_a, list_b);
	if (is_splited)
		free_splited_argv(argv);
}
