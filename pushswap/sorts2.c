/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:40:53 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 17:28:17 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../common/push_swap.h"

void	first_step_one(t_node **listA, t_node **listB)
{
	while (*listA != get_cheapest(*listA)
		&& *listB != get_cheapest(*listA)->target_node)
	{
		if (get_cheapest(*listA)->is_above_median
			&& get_cheapest(*listA)->target_node->is_above_median)
			rr(listA, listB, 1);
		else if (!get_cheapest(*listA)->is_above_median
			&& !get_cheapest(*listA)->target_node->is_above_median)
			rrr(listA, listB, 1);
		else
			break ;
	}
}
