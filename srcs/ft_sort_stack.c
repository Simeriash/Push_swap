/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/07 15:34:23 by julauren         ###   ########.fr       */
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
	t_stack	b;
	int		len;

	len = a->nb;
	if (ft_stack_sorted(a))
		return (0);
	b.list = malloc(sizeof (int) * len);
	if (!(b.list))
		return (-1);
	b.nb = 0;
	a->max = ft_max(a, INT_MAX);
	while (a->nb > 3)
	{
		if ((a->nb - 1) == a->max)
		{
			ft_rotate_a(a);
			a->max = 0;
			continue ;
		}
		if (b.nb > 2 && (a->list[a->nb - 1] < b.list[b.nb - 1]))
		{
			b.max = ft_max(&b, a->list[a->nb - 1]);
			if (b.max >= 0)
			{
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
			}
			else
			{
				b.min = ft_min(&b, a->list[a->nb - 1]);
				b.median = (b.nb - 1) / 2;
				if (b.min > b.median)
				{
					while (b.min < b.nb)
					{
						ft_rotate_b(&b);
						(b.min)++;
					}
				}
				else
				{
					while (b.min > 0)
					{
						ft_reverse_rotate_b(&b);
						(b.min)--;
					}
				}
			}
		}
		ft_push_b(&b, a);
		if (b.nb == 2 && (b.list[1] < b.list[0]))
			ft_swap_b(&b);
	}
	if (a->nb > 2 && !(ft_stack_sorted(a)))
	{
		if (a->max == 2)
			ft_rotate_a(a);
		if (a->max == 1)
			ft_reverse_rotate_a(a);
		if (a->list[2] > a->list[1])
			ft_swap_a(a);
	}
	while (a->nb < len)
	{
		a->min = ft_min(a, b.list[b.nb - 1]);
		if (a->min)
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
		else
		{
			a->max = ft_max(a, b.list[b.nb - 1]);
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
		ft_push_a(a, &b);
	}
	a->max = ft_max(a, INT_MAX);
	if (a->max)
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
	free(b.list);
	return (0);
}
