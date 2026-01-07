/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 12:08:03 by julauren          #+#    #+#             */
/*   Updated: 2026/01/06 14:52:04 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_part_1(t_stack *b)
{
	b->median = (b->nb - 1) / 2;
	if (b->max >= b->median)
	{
		while (b->max < (b->nb - 1))
		{
			ft_rotate_b(b);
			(b->max)++;
		}
	}
	else
	{
		while (b->max >= 0)
		{
			ft_reverse_rotate_b(b);
			(b->max)--;
		}
	}
}

static void	ft_part_2(t_stack *b)
{
	b->median = (b->nb - 1) / 2;
	if (b->min > b->median)
	{
		while (b->min < b->nb)
		{
			ft_rotate_b(b);
			(b->min)++;
		}
	}
	else
	{
		while (b->min > 0)
		{
			ft_reverse_rotate_b(b);
			(b->min)--;
		}
	}
}

void	ft_push_to_b(t_stack *a, t_stack *b)
{
	while (a->nb > 3)
	{
		if ((a->nb - 1) == a->max)
		{
			ft_rotate_a(a);
			a->max = 0;
		}
		if (b->nb > 2 && (a->list[a->nb - 1] < b->list[b->nb - 1]))
		{
			b->max = ft_max(b, a->list[a->nb - 1]);
			if (b->max >= 0)
				ft_part_1(b);
			else
			{
				b->min = ft_min(b, a->list[a->nb - 1]);
				ft_part_2(b);
			}
		}
		ft_push_b(b, a);
		if (b->nb == 2 && (b->list[1] < b->list[0]))
			ft_swap_b(b);
	}
}
