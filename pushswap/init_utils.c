/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:30:17 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 17:28:07 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/push_swap.h"

void	set_indexes_and_median(t_node *l_list)
{
	int	i;
	int	median;

	i = 0;
	median = calculate_length(l_list) / 2;
	if (!l_list)
		return ;
	while (l_list)
	{
		l_list->index = i;
		if (i <= median)
			l_list->is_above_median = 1;
		else
			l_list->is_above_median = 0;
		l_list = l_list->next;
		i++;
	}
}

void	set_target_nodes_a(t_node *listA, t_node *listB)
{
	t_node	*target_node;
	t_node	*curr;
	int		number;

	while (listA)
	{
		number = INT_MIN;
		curr = listB;
		while (curr)
		{
			if (listA->x > curr->x && number < curr->x)
			{
				number = curr->x;
				target_node = curr;
			}
			curr = curr->next;
		}
		if (number == INT_MIN)
			listA->target_node = find_biggest(listB);
		else
			listA->target_node = target_node;
		listA = listA->next;
	}
}

void	set_push_costs_a(t_node *listA, t_node *listB)
{
	int	length_list_a;
	int	length_list_b;

	length_list_a = calculate_length(listA);
	length_list_b = calculate_length(listB);
	while (listA)
	{
		listA->push_cost = listA->index;
		if (!listA->is_above_median)
			listA->push_cost = length_list_a - listA->index;
		if (listA->target_node->is_above_median)
			listA->push_cost += listA->target_node->index;
		else
			listA->push_cost += length_list_b - listA->target_node->index;
		listA = listA->next;
	}
}

//find the node with the less push cost and assign is_cheapest to 1
void	set_is_cheapest(t_node *l_list)
{
	long	numb;
	t_node	*ptr;

	numb = LONG_MAX;
	while (l_list)
	{
		if (l_list->push_cost < numb)
		{
			numb = l_list->push_cost;
			ptr = l_list;
		}
		l_list->is_cheapest = 0;
		l_list = l_list->next;
	}
	ptr->is_cheapest = 1;
}

void	set_values_a(t_node *listA, t_node *listB)
{
	set_indexes_and_median(listA);
	set_indexes_and_median(listB);
	set_target_nodes_a(listA, listB);
	set_push_costs_a(listA, listB);
	set_is_cheapest(listA);
}
