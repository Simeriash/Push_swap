/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turkish_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 13:55:34 by julauren          #+#    #+#             */
/*   Updated: 2026/01/07 11:25:03 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_stack_sorted(t_stack *a)
{
	int	i;

	i = 0;
	while (i < a->nb - 1)
	{
		if (a->list[i] < a->list[i + 1])
			return (0);
		i++;
	}
	return (1);
}

static void	ft_stack_in_order(t_stack *a)
{
	if (!(ft_stack_sorted(a)))
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
}

int	ft_turkish_sort(t_stack *a)
{
	t_stack	b;
	int		len;

	len = a->nb;
	b.list = malloc(sizeof (int) * len);
	if (!(b.list))
		return (-1);
	b.nb = 0;
	a->max = ft_max(a, INT_MAX);
	ft_push_to_b(a, &b);
	if (a->max == 2)
		ft_rotate_a(a);
	else if (a->max == 1)
		ft_reverse_rotate_a(a);
	if (a->list[a->nb - 1] > a->list[ a->nb - 2])
		ft_swap_a(a);
	ft_push_to_a(a, &b, len);
	a->max = ft_max(a, INT_MAX);
	ft_stack_in_order(a);
	free(b.list);
	return (0);
}
