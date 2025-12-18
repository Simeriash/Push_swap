/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:13:14 by julauren          #+#    #+#             */
/*   Updated: 2025/12/18 17:15:16 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap_stack(t_stack *a)
{
	int	i;
	int	tmp;
	int	end;

	i = 0;
	end = (a->nb) / 2;
	while (i < end)
	{
		tmp = a->list[i];
		a->list[i] = a->list[a->nb - 1 - i];
		a->list[a->nb - 1 - i] = tmp;
		i++;
	}
}

static int	ft_stack_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->nb - 1)
	{
		if (a->list[i] > a->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_format_stack(t_stack *a)
{
	int	i;
	int	j;
	int	end;

	i = 0;
	end = a->nb - 1;
	while (i < end)
	{
		j = i + 1;
		while (j <= end)
		{
			if (a->list[j] == a->list[i])
				return (-2);
			j++;
		}
		i++;
	}
	if (ft_stack_sorted(a))
		return (-1);
	ft_swap_stack(a);
	return (0);
}
