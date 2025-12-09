/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/09 14:18:39 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_next_index(t_stack *a, t_stack *b, int *threshold, int delta)
{
	int	tmp;
	int	i;

	tmp = *threshold;
	a->max = a->nb - 1;
	while (a->max >= 0 && (a->list[a->max] > (*threshold + delta)))
		(a->max)--;
	while (a->max == -1)
	{
		a->max = a->nb - 1;
		tmp++;
		while (a->max >= 0 && (a->list[a->max] > (tmp + delta)))
			(a->max)--;
	}
	a->min = 0;
	while ((a->min <= (a->nb - 1)) && (a->list[a->min] > (*threshold + delta)) && a->min < a->max)
		(a->min)++;
	if ((a->nb - a->max) <= (a->min + 1))
		i = a->max;
	else
		i = a->min;
	a->median = (a->nb - 1) / 2;
	if (i >= a->median)
	{
		while (i < (a->nb - 1))
		{
			ft_rotate_a(a);
			i++;
		}
	}
	else
	{
		if (a->nb > 1)
		{
			while (i >= 0)
			{
				ft_reverse_rotate_a(a);
				i--;
			}
		}
	}
	if (a->list[a->nb - 1] <= (tmp + delta))
	{
		ft_push_b(b, a);
		if (b->nb > 1 && a->nb > 1 && (a->list[a->nb - 1] <= tmp))
			ft_rotate_b(b);
		(*threshold)++;
	}
}

int	ft_sort_stack(t_stack *a)
{
	t_stack	b;
	int		delta;
	int		threshold;

	if (ft_stack_sorted(a))
		return (0);
	b.list = malloc(sizeof (int) * (a->nb));
	if (!(b.list))
		return (-1);
	b.nb = 0;
	delta = (a->nb) / 20 + 3;
	a->min = ft_min(a, INT_MIN);
	threshold = a->list[a->min];
	while (a->nb > 0)
	{
		if (a->list[a->nb - 1] <= (threshold + delta))
		{
			ft_push_b(&b, a);
			if (b.nb > 1 && a->nb > 1 && (b.list[b.nb - 1] <= threshold))
				ft_rotate_b(&b);
			threshold++;
		}
		else
			ft_next_index(a, &b, &threshold, delta);
	}
	while (b.nb > 0)
	{
		b.max = ft_max(&b, INT_MAX);
		b.median = (b.nb - 1) / 2;
		if (b.max >= b.median)
		{
			while (b.max < (b.nb - 1))
			{
				ft_rotate_b(&b);
				(b.max)++;
			}
		}
		else
		{
			while (b.max >= 0)
			{
				ft_reverse_rotate_b(&b);
				(b.max)--;
			}
		}
		ft_push_a(a, &b);
	}
	free(b.list);
	return (0);
}
