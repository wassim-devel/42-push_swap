/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:49:27 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/13 11:57:11 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/push_swap.h"
#include "get_next_line.h"

int	check_the_rest(char *line, t_node **list_a, t_node **list_b)
{
	if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		ra(list_a, 0);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rb(list_b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'a'
		&& line[3] == '\n')
		rra(list_a, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'b'
		&& line[3] == '\n')
		rrb(list_b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == 'r'
		&& line[3] == '\n')
		rrr(list_a, list_b, 0);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
		rr(list_a, list_b, 0);
	else
		return (0);
	return (1);
}

int	do_operations(char *line, t_node **list_a, t_node **list_b)
{
	while (line)
	{
		if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
			pa(list_a, list_b, 0);
		else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
			pb(list_a, list_b, 0);
		else if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
			sa(list_a, 0);
		else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
			sb(list_b, 0);
		else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
			ss(list_a, list_b, 0);
		else
			if (!check_the_rest(line, list_a, list_b))
				return (0);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	return (1);
}

int	check_the_sorting(t_node **list_a, t_node **list_b)
{
	char	*line;

	line = get_next_line(0);
	if (!do_operations(line, list_a, list_b))
		return (0);
	if (!check_is_sort(*list_a))
		write(1, "KO\n", 3);
	else if (check_is_sort(*list_a))
		write(1, "OK\n", 3);
	free_l_list(list_a);
	free_l_list(list_b);
	return (1);
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
	if (!check_the_sorting(&list_a, &list_b))
		write_error_bonus(argv, &list_a, &list_b, is_splited);
	if (is_splited)
		free_splited_argv(argv);
}
