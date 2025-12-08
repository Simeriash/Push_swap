/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/08 13:54:00 by julauren         ###   ########.fr       */
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

static int	ft_init_stack(t_stack *x)
{
	int	threshold;

	x->min = ft_min(x, INT_MIN);
	threshold = x->list[x->min];
	x->median = (x->nb - 1) / 2;
	if (x->min >= x->median)
	{
		while (x->min < (x->nb - 1))
		{
			ft_rotate_a(x);
			(x->min)++;
		}
	}
	else
	{
		while (x->min >= 0)
		{
			ft_reverse_rotate_a(x);
			(x->min)--;
		}
	}
	return (threshold);
}

static int	ft_next_index(t_stack *x, int *threshold, int delta)
{
	x->max = x->nb - 1;
	while ((x->list[x->max] > (threshold + delta)) && x->max >= 0)
		(x->max)--;
	if (x->max == -1)
	{

	}
	x->min = 0;
	while ((x->list[x->min] > (threshold + delta)) && (x->min <= (x->nb - 1)))
		(x->min)++;
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
	delta = (a->nb) / 20 + 7;
	threshold = ft_init_stack(a);
	while (a->nb > 0)
	{
		if (a->list[a->nb - 1] <= threshold + delta)
		{
			ft_push_b(&b, a);
			if (a->list[a->nb - 1] <= (threshold + (delta / 2)))
				ft_rotate_b(&b);
			threshold++;
		}
		else
		{
			// ft_rotate_a(a);
			
		}
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
