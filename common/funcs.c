/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 14:43:48 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 16:23:57 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_node **listA, int print_it)
{
	t_node	*temp;
	t_node	*curr;

	if ((*listA)->next == NULL || *listA == NULL)
		return ;
	curr = *listA;
	temp = curr->next;
	curr->next = temp->next;
	temp->next = curr;
	*listA = temp;
	if (print_it)
		write(1, "sa\n", 3);
}

void	sb(t_node **listB, int print_it)
{
	t_node	*temp;
	t_node	*curr;

	if (*listB == NULL || (*listB)->next == NULL)
		return ;
	curr = *listB;
	temp = curr->next;
	curr->next = temp->next;
	temp->next = curr;
	*listB = temp;
	if (print_it)
		write(1, "sb\n", 3);
}

void	pa(t_node **listA, t_node **listB, int print_it)
{
	t_node	*temp;

	temp = *listB;
	if (*listB == NULL)
		return ;
	*listB = (*listB)->next;
	temp->next = *listA;
	*listA = temp;
	if (print_it)
		write(1, "pa\n", 3);
}

void	pb(t_node **listA, t_node **listB, int print_it)
{
	t_node	*temp;

	if (*listA == NULL)
		return ;
	temp = *listA;
	*listA = (*listA)->next;
	temp->next = *listB;
	*listB = temp;
	if (print_it)
		write(1, "pb\n", 3);
}

void	ra(t_node **listA, int print_it)
{
	t_node	*first;
	t_node	*current;

	first = *listA;
	current = *listA;
	if (*listA == NULL || (*listA)->next == NULL)
		return ;
	while (current->next != NULL)
		current = current->next;
	current->next = first;
	*listA = first->next;
	first->next = NULL;
	if (print_it == 1)
		write(1, "ra\n", 3);
}
