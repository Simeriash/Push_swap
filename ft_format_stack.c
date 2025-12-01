/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:13:14 by julauren          #+#    #+#             */
/*   Updated: 2025/12/01 10:25:01 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_swap(t_stack *a)
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
	ft_swap(a);
	return (0);
}
