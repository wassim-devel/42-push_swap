/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:19:06 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/13 11:56:12 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//return 1 if sorted, 0 if not, 2 if emptylist
int	check_is_sort(t_node *list)
{
	if (list == NULL)
		return (2);
	while (list->next != NULL)
	{
		if (!(list->x < list->next->x))
		{
			return (0);
		}
		list = list->next;
	}
	return (1);
}

//return 1 if it's number, 0 if not
int	is_number(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-'))
			return (0);
		i++;
	}
	return (1);
}

void	write_error(char **argv, int is_splited)
{
	if (is_splited)
		free_splited_argv(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	write_error_bonus(char **argv, t_node **list_a,
		t_node **list_b, int is_splited)
{
	if (is_splited)
		free_splited_argv(argv);
	free_l_list(list_a);
	free_l_list(list_b);
	write(2, "Error\n", 6);
	exit(1);
}

//checks if there's an error, if there's error the program exit with code 1
void	check_errors(int nb_of_arg, char **args, int is_splited)
{
	int	i;
	int	j;

	i = 0;
	while (i < nb_of_arg)
	{
		if (is_number(args[i]) != 1)
			write_error(args, is_splited);
		if (ft_atol(args[i]) > (INT_MAX) || ft_atol(args[i]) < INT_MIN)
			write_error(args, is_splited);
		j = i + 1;
		while (j < nb_of_arg)
		{
			if (ft_atoi(args[i]) == ft_atoi(args[j]))
				write_error(args, is_splited);
			j++;
		}
		i++;
	}
}
