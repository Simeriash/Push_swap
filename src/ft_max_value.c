/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 14:15:44 by julauren          #+#    #+#             */
/*   Updated: 2025/12/20 12:40:26 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_max_value(t_stack *x)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = 0;
	tmp = x->list[i];
	while (i < x->nb)
	{
		if (x->list[i] > tmp)
		{
			tmp = x->list[i];
			index = i;
		}
		i++;
	}
	return (index);
}
