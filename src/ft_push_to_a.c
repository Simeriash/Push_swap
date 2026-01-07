/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 16:21:02 by julauren          #+#    #+#             */
/*   Updated: 2025/12/21 13:57:55 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_part_1(t_stack *a)
{
	a->median = (a->nb - 1) / 2;
	if (a->min >= a->median)
	{
		while (a->min < (a->nb - 1))
		{
			ft_rotate_a(a);
			(a->min)++;
		}
	}
	else
	{
		while (a->min >= 0)
		{
			ft_reverse_rotate_a(a);
			(a->min)--;
		}
	}
}

static void	ft_part_2(t_stack *a)
{
	a->median = (a->nb - 1) / 2;
	if (a->max > a->median)
	{
		while (a->max < a->nb)
		{
			ft_rotate_a(a);
			(a->max)++;
		}
	}
	else
	{
		while (a->max > 0)
		{
			ft_reverse_rotate_a(a);
			(a->max)--;
		}
	}
}

void	ft_push_to_a(t_stack *a, t_stack *b, int len)
{
	while (a->nb < len)
	{
		a->min = ft_min(a, b->list[b->nb - 1]);
		if (a->min >= 0)
			ft_part_1(a);
		else
		{
			a->max = ft_max(a, b->list[b->nb - 1]);
			ft_part_2(a);
		}
		ft_push_a(a, b);
	}
}
