/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/03 15:35:17 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_min(t_stack *x, int min)
{
	int	i;
	int	tmp;
	int	index;

	i = 0;
	index = 0;
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
	index = 0;
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

int	ft_sort_stack(t_stack *a)
{
	t_stack	b;

	b.list = malloc(sizeof (int) * (a->nb));
	if (!(b.list))
		return (-1);
	b.nb = 0;
	a->i = ft_max(a, INT_MAX);
	a->j = ft_max(a, a->i);
	while ((a->i - a->j) == 1)
	{
		a->i = a->j;
		a->j = ft_max(a, a->i);
	}
	if (a->i == 0 && a->j == 0)
	{
		free(b.list);
		return (-1);
	}
	a->median = (a->nb) / 2;
	if (a->i > a->median)
	{
		if (a->j > a->median)
		{
			if (a->i > a->j)
			{
				while (a->i < (a->nb - 1))
					ft_push_b(&b, a);
				if ((a->i - a->j) == 1)
				{
					ft_swap_a(a);
					a->i = a->j;
				}
				else
				{
					ft_rotate_a(a);
					(a->j)++;
					a->i = 0;
					while (a->j < a->nb)
						ft_push_b(&b, a);
					ft_reverse_rotate_a(a);
					ft_push_a(a, &b);
					a->i = a->j;
				}
			}
			else
			{
				while (a->j < (a->nb - 1))
					ft_push_b(&b, a);
				if ((a->j - a->i) == 1)
				{
					ft_swap_a(a);
					a->i = a->j;
				}
				else
				{
					ft_push_b(&b, a);
					b.j = b.nb - 1;
					while (a->i < (a->nb - 1))
					{
						ft_push_b(&b, a);
						if (((a->nb - a->i) > 1) && ((b.nb - b.j) > 1))
						{
							ft_both_rotate(a, &b);
							(a->i)++;
							(b.j)++;
						}
					}
					while (b.j < (b.nb - 1))
					{
						ft_rotate_b(&b);
						(b.j)++;
					}
					ft_push_a(a, &b);
					(a->i)++;
				}
			}
		}
		else
		{
			while (a->j >= 0)
			{
				ft_reverse_rotate_a(a);
				(a->i)--;
				(a->j)--;
			}
			a->j = a->nb - 1;
			if ((a->j - a->i) == 1)
			{
				ft_swap_a(a);
				a->i = a->j;
			}
			else
			{
				ft_push_b(&b, a);
				b.j = b.nb - 1;
				a->median = (a->nb) / 2;
				if (a->i > a->median)
				{
					while (a->i < (a->nb - 1))
					{
						ft_push_b(&b, a);
						if (((a->nb - a->i) > 1) && ((b.nb - b.j) > 1))
						{
							ft_both_rotate(a, &b);
							(a->i)++;
							(b.j)++;
						}
					}
					while (b.j < (b.nb - 1))
					{
						ft_rotate_b(&b);
						(b.j)++;
					}
					ft_push_a(a, &b);
					(a->i)++;
				}
				else
				{
					while (a->i >= 0)
					{
						ft_reverse_rotate_a(a);
						(a->i)--;
					}
					a->i = a->nb - 1;
					ft_push_a(a, &b);
					(a->i)++;
				}
			}
		}
	}
	else
	{
		if (a->j < a->median)
		{
			// i & j dans la moitié inf
		}
		else
		{
			// i dans la moitié inf & j dans la moitié sup
		}
	}
	free(b.list);
	return (0);
}
