/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/18 18:01:53 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_up_max(t_stack *x, char c)
{
	x->median = (x->nb - 1) / 2;
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

static void	ft_full_stock_b(t_stack *a, t_stack *b, int *pivot)
{
	ft_push_b(b, a);
	if (b->nb > 1 && (b->list[b->nb - 1] <= *pivot))
		ft_rotate(b, 'b');
	(*pivot)++;
}

static void	ft_next_index(t_stack *a, t_stack *b, int *pivot, int delta)
{
	int	tmp;

	tmp = a->list[ft_min(a, INT_MIN)];
	while (a->max == -1)
	{
		a->max = a->nb - 1;
		while (a->max >= 0 && (a->list[a->max] > (tmp + delta)))
			(a->max)--;
		tmp++;
	}
	a->min = 0;
	while ((a->min <= (a->nb - 1)) && (a->list[a->min] > (tmp + delta))
		&& a->min < a->max)
		(a->min)++;
	if ((a->nb - a->max - 1) > (a->min + 1))
		a->max = a->min;
	if (a->nb > 1)
		ft_up_max(a, 'a');
	ft_full_stock_b(a, b, &tmp);
	(*pivot) = tmp;
}

static void	ft_special_k(t_stack *a, t_stack *b, int pivot, int delta)
{
	while (a->nb > 0)
	{
		if (a->list[a->nb - 1] <= (pivot + delta))
			ft_full_stock_b(a, b, &pivot);
		else
		{
			a->max = a->nb - 1;
			while (a->max >= 0 && (a->list[a->max] > (pivot + delta)))
				(a->max)--;
			if (a->max == -1)
				ft_next_index(a, b, &pivot, delta);
			else
				ft_rotate(a, 'a');
		}
	}
	while (b->nb > 0)
	{
		b->max = ft_max(b, INT_MAX);
		if (b->nb > 1)
			ft_up_max(b, 'b');
		ft_push_a(a, b);
	}
}

int	ft_sort_stack(t_stack *a)
{
	t_stack	b;
	int		delta;
	int		pivot;

	b.list = malloc(sizeof (int) * (a->nb));
	if (!(b.list))
		return (-1);
	b.nb = 0;
	delta = (a->nb) / 20 + 7;
	a->min = ft_min(a, INT_MIN);
	pivot = a->list[a->min];
	ft_special_k(a, &b, pivot, delta);
	free(b.list);
	return (0);
}
