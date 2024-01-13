/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 18:39:24 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 18:23:09 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_cheapest(t_node *l_list)
{
	if (l_list == NULL)
		return (NULL);
	while (l_list)
	{
		if (l_list->is_cheapest == 1)
			return (l_list);
		l_list = l_list->next;
	}
	return (NULL);
}

t_node	*find_smallest(t_node *l_list)
{
	t_node	*smallest;
	int		numb;

	if (!l_list)
		return (NULL);
	numb = INT_MAX;
	while (l_list != NULL)
	{
		if (l_list->x < numb)
		{
			numb = l_list->x;
			smallest = l_list;
		}
		l_list = l_list->next;
	}
	return (smallest);
}

void	free_l_list(t_node **l_list)
{
	t_node	*temp;
	t_node	*curr;

	if (!l_list)
		return ;
	curr = *l_list;
	while (curr)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	l_list = NULL;
}

void	add_end(t_node **to_add, int value)
{
	t_node	*new_node;
	t_node	*curr;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		exit(1);
	new_node->x = value;
	new_node->next = NULL;
	if (*to_add == NULL)
	{
		*to_add = new_node;
		return ;
	}
	curr = *to_add;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
}

void	fill_list_a(int argc, char **argv, t_node **list_a)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		add_end(list_a, ft_atoi(argv[i]));
		i++;
	}
}
