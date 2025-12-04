/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/04 15:16:32 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// static int	ft_min(t_stack *x, int min)
// {
// 	int	i;
// 	int	tmp;
// 	int	index;

// 	i = 0;
// 	index = 0;
// 	tmp = INT_MAX;
// 	while (i < x->nb)
// 	{
// 		if ((x->list[i] > min) && (tmp > x->list[i]))
// 		{
// 			tmp = x->list[i];
// 			index = i;
// 		}
// 		i++;
// 	}
// 	return (index);
// }

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
	int		n;

	b.list = malloc(sizeof (int) * (a->nb));
	if (!(b.list))
		return (-1);
	b.nb = 0;
	a->i = ft_max(a, INT_MAX);
	a->j = ft_max(a, a->list[a->i]);
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
	n = 0;
	while (n < 10)
	{
		a->median = (a->nb) / 2;
		if (a->i > a->median)
		{
			if (a->j > a->median)
			{
				// i & j dans la moitié sup
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
						a->i = -1;
						while (a->j < (a->nb - 1))
						{
							ft_rotate_a(a);
							(a->j)++;
							(a->i)++;
						}
						ft_push_b(&b, a);
						while (a->i >= 0)
						{
							ft_reverse_rotate_a(a);
							(a->i)--;
						}
						ft_push_a(a, &b);
						a->i = a->j;
					}
				}
				else
				{
					if ((a->j - a->i) == 1)
						a->i = a->j;
					else
					{
						while (a->j < a->nb)
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
				// i dans la moitié sup & j dans la moitié inf
				while (a->j >= 0)
				{
					ft_reverse_rotate_a(a);
					(a->i)--;
					(a->j)--;
				}
				a->j = a->nb - 1;
				if (a->i == 0)
				{
					ft_reverse_rotate_a(a);
					ft_swap_a(a);
					a->i = a->nb - 1;
				}
				else if ((a->j - a->i) == 1)
						a->i = a->j;
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
				if (a->i > a->j)
				{
					while (a->j >= 0)
					{
						ft_reverse_rotate_a(a);
						(a->i)--;
						(a->j)--;
					}
					a->j = a->nb - 1;
					if (a->i == 0)
					{
						ft_reverse_rotate_a(a);
						ft_swap_a(a);
						a->i = a->nb - 1;
					}
					else
					{
						ft_push_b(&b, a);
						b.j = b.nb - 1;
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
				else
				{
					if ((a->j - a->i) == 1)
						a->i = a->j;
					else
					{
						while (a->j >= 0)
						{
							ft_reverse_rotate_a(a);
							(a->i)--;
							(a->j)--;
							if (a->i == -1)
								a->i = a->nb - 1;
						}
						b.j = b.nb;
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
				// i dans la moitié inf & j dans la moitié sup
				while (a->j < a->nb)
					ft_push_b(&b, a);
				b.j = b.nb - 1;
				while (a->i >= 0)
				{
					ft_reverse_rotate_a(a);
					(a->i)--;
				}
				ft_push_a(a, &b);
				a->i = a->nb - 1;
			}
		}
		n++;
		a->j = ft_max(a, a->list[a->i]);
	}
	free(b.list);
	return (0);
}
