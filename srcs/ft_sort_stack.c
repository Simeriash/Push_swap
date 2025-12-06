/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/06 18:01:53 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_min(t_stack *x, int min)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = -1;
	tmp = INT_MAX;
	while (i < x->nb)
	{
		if ((x->list[i] > min) && (tmp > x->list[i]))
		{
			tmp = x->list[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static int	ft_max(t_stack *x, int max)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = -1;
	tmp = INT_MIN;
	while (i < x->nb)
	{
		if ((x->list[i] < max) && (tmp < x->list[i]))
		{
			tmp = x->list[i];
			index = i;
		}
		i++;
	}
	return (index);
}

static int	ft_stack_sorted(t_stack *x)
{
	int	i;

	i = 0;
	while (i < x->nb - 1)
	{
		if (x->list[i] < x->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	ft_sort_stack(t_stack *a)
{
	t_stack b;

	if (ft_stack_sorted(a))
		return (0);
	b.list = malloc(sizeof (int) * (a->nb));
	if (!(b.list))
		return (-1);
	b.nb = 0;
	a->max = ft_max(a, INT_MAX);
	a->min = ft_min(a, INT_MIN);
	while (a->nb > 3)
	{
		if ((a->nb - 1) == a->max)
		{
			ft_rotate_a(a);
			a->max = 0;
		}
		if (b.nb > 1 && a->nb > 0 && (a->list[a->nb - 1] < b.list[b.nb - 1]))
		{
			b.max = b.nb - 2;
			while (b.max >= 0 && (a->list[a->nb - 1] < b.list[b.max]))
				(b.max)--;
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
					b.max = b.nb - 1;
				}
			}
		}
		ft_push_b(&b, a);
		if (a->min == a->nb)
			ft_rotate_b(&b);
		if (b.nb == 2 && (b.list[1] < b.list[0]))
			ft_swap_b(&b);
	}
	if (!(ft_stack_sorted(a)))
	{
		if (a->max == 2)
			ft_rotate_a(a);
		if (a->max == 1)
			ft_reverse_rotate_a(a);
		if (a->list[2] > a->list[1])
			ft_swap_a(a);
	}
	free(b.list);
	return (0);
}
