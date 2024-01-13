/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:50:36 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 16:25:06 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_node **listB, int print_it)
{
	t_node	*first;
	t_node	*current;

	first = *listB;
	current = *listB;
	if (*listB == NULL || (*listB)->next == NULL)
		return ;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	*listB = first->next;
	first->next = NULL;
	if (print_it == 1)
		write(1, "rb\n", 3);
}

void	rr(t_node **listA, t_node **listB, int print_it)
{
	ra(listA, 0);
	rb(listB, 0);
	if (print_it)
		write(1, "rr\n", 3);
}

void	rra(t_node **listA, int print_it)
{
	t_node	*current;
	t_node	*previous;

	current = *listA;
	previous = NULL;
	if (*listA == NULL || (*listA)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = *listA;
	*listA = current;
	if (print_it == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_node **listB, int print_it)
{
	t_node	*current;
	t_node	*previous;

	current = *listB;
	previous = NULL;
	if (*listB == NULL || (*listB)->next == NULL)
		return ;
	while (current->next != NULL)
	{
		previous = current;
		current = current->next;
	}
	previous->next = NULL;
	current->next = *listB;
	*listB = current;
	if (print_it == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_node **listA, t_node **listB, int print_it)
{
	rra(listA, 0);
	rrb(listB, 0);
	if (print_it)
		write(1, "rrr\n", 4);
}
