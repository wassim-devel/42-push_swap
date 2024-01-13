/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlalaoui <wlalaoui@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:14:17 by wlalaoui          #+#    #+#             */
/*   Updated: 2023/12/12 14:58:20 by wlalaoui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	int	number;
	int	signe;

	number = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - 48);
		str++;
	}
	return (number * signe);
}

long	ft_atol(const char *str)
{
	long	number;
	long	signe;

	number = 0;
	signe = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 + (*str - 48);
		str++;
	}
	return (number * signe);
}

int	count_number_of_args(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	calculate_length(t_node *list)
{
	int	i;

	i = 0;
	if (list == NULL)
		return (0);
	while (list != NULL)
	{
		i++;
		list = list->next;
	}
	return (i);
}

t_node	*find_biggest(t_node *listA)
{
	t_node	*biggest;
	int		numb;

	if (!listA)
		return (NULL);
	numb = INT_MIN;
	while (listA != NULL)
	{
		if (listA->x > numb)
		{
			numb = listA->x;
			biggest = listA;
		}
		listA = listA->next;
	}
	return (biggest);
}
