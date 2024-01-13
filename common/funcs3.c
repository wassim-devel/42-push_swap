/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:09:15 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 16:25:52 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **listA, t_node **listB, int print_it)
{
	sa(listA, 0);
	sb(listB, 0);
	if (print_it)
		write(1, "ss\n", 3);
}
