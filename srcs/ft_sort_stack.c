/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/09 16:53:12 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_up_max(t_stack *x, char c)
{
	x->median = (x->nb - 1) / 2;
	if (x->nb > 1)
	{
		if (x->max >= x->median)
		{
			while (x->max < (x->nb - 1))
			{
				ft_rotate(x, c);
				(x->max)++;
			}
		}
		else
		{
			while (x->max >= 0)
			{
				ft_reverse_rotate(x, c);
				(x->max)--;
			}
		}
	}
}

static void	ft_full_stock_b(t_stack *a, t_stack *b, int *threshold, int delta)
{
	if (a->list[a->nb - 1] <= (*threshold + delta))
	{
		ft_push_b(b, a);
		if (b->nb > 1 && a->nb > 1 && (b->list[b->nb - 1] <= *threshold))
			ft_rotate(b, 'b');
		(*threshold)++;
	}
}

static void	ft_next_index(t_stack *a, t_stack *b, int *threshold, int delta)
{
	int	tmp;

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
	while ((a->min <= (a->nb - 1)) && (a->list[a->min] > (*threshold + delta))
		&& a->min < a->max)
		(a->min)++;
	if ((a->nb - a->max) > (a->min + 1))
		a->max = a->min;
	ft_up_max(a, 'a');
	ft_full_stock_b(a, b, &tmp, delta);
	(*threshold)++;
}

static void	ft_butterfly(t_stack *a, t_stack *b, int threshold, int delta)
{
	while (a->nb > 0)
	{
		if (a->list[a->nb - 1] <= (threshold + delta))
			ft_full_stock_b(a, b, &threshold, delta);
		else
			ft_next_index(a, b, &threshold, delta);
	}
	while (b->nb > 0)
	{
		b->max = ft_max(b, INT_MAX);
		ft_up_max(b, 'b');
		ft_push_a(a, b);
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
	ft_butterfly(a, &b, threshold, delta);
	free(b.list);
	return (0);
}
