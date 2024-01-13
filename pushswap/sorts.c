/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:59:44 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 16:26:55 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/push_swap.h"

void	set_target_nodes_b(t_node *listA, t_node *listB)
{
	t_node	*target_node;
	t_node	*curr;
	long	number;

	while (listB)
	{
		number = LONG_MAX;
		curr = listA;
		while (curr)
		{
			if (listB->x < curr->x && number > curr->x)
			{
				number = curr->x;
				target_node = curr;
			}
			curr = curr->next;
		}
		if (number == LONG_MAX)
			listB->target_node = find_smallest(listA);
		else
			listB->target_node = target_node;
		listB = listB->next;
	}
}

void	set_values_b(t_node *listA, t_node *listB)
{
	set_indexes_and_median(listA);
	set_indexes_and_median(listB);
	set_target_nodes_b(listA, listB);
}

void	sort_three(t_node **listA)
{
	t_node	*biggest;

	biggest = find_biggest(*listA);
	if (*listA == biggest)
		ra(listA, 1);
	else if ((*listA)->next == biggest)
		rra(listA, 1);
	if ((*listA)->x > (*listA)->next->x)
		sa(listA, 1);
}

void	first_step(t_node **listA, t_node **listB)
{
	while (!check_is_sort(*listA) && calculate_length(*listA) > 3)
	{
		set_values_a(*listA, *listB);
		first_step_one(listA, listB);
		while (*listA != get_cheapest(*listA))
		{
			if (get_cheapest(*listA)->is_above_median)
				ra(listA, 1);
			else if (!(get_cheapest(*listA)->is_above_median))
				rra(listA, 1);
		}
		while (*listB != (*listA)->target_node)
		{
			if ((*listA)->target_node->is_above_median)
				rb(listB, 1);
			else if (!(*listA)->target_node->is_above_median)
				rrb(listB, 1);
		}
		pb(listA, listB, 1);
	}
}

void	sort_lists(t_node **listA, t_node **listB)
{
	pb(listA, listB, 1);
	if (calculate_length(*listA) > 3)
		pb(listA, listB, 1);
	first_step(listA, listB);
	sort_three(listA);
	while (*listB != NULL)
	{
		set_values_b(*listA, *listB);
		while (*listA != (*listB)->target_node)
		{
			if ((*listB)->target_node->is_above_median)
				ra(listA, 1);
			else if (!(*listB)->target_node->is_above_median)
				rra(listA, 1);
		}
		pa(listA, listB, 1);
	}
	while (!check_is_sort(*listA))
	{
		set_values_b(*listA, *listB);
		if (find_smallest(*listA)->is_above_median)
			ra(listA, 1);
		else if (!find_smallest(*listA)->is_above_median)
			rra(listA, 1);
	}
}
