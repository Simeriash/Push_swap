/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:15:44 by julauren          #+#    #+#             */
/*   Updated: 2025/12/18 17:05:19 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_min(t_stack *x, int min)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = -1;
	tmp = INT_MAX;
	while (i < x->nb)
	{
		if (x->list[i] == min)
			return (i);
		if ((x->list[i] > min) && (tmp > x->list[i]))
		{
			tmp = x->list[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int	ft_max(t_stack *x, int max)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = -1;
	tmp = INT_MIN;
	while (i < x->nb)
	{
		if (x->list[i] == max)
			return (i);
		if ((x->list[i] < max) && (tmp < x->list[i]))
		{
			tmp = x->list[i];
			index = i;
		}
		i++;
	}
	return (index);
}
