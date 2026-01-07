/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_k_distribution_sort.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/21 14:03:11 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_up_max(t_stack *b)
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

static void	ft_special_k(t_stack *a, t_stack *b, int *list_index)
{
	int		delta;
	int		pivot;

	delta = (a->nb) / 20 + 7;
	pivot = 0;
	while (a->nb > 0)
	{
		if (list_index[a->nb - 1] <= (pivot + delta))
		{
			ft_push_b(b, a);
			if (b->nb > 1 && (list_index[a->nb] <= pivot))
				ft_rotate_b(b);
			pivot++;
		}
		else if (a->nb > 1)
			ft_rotate_al(a, list_index);
	}
	while (b->nb > 0)
	{
		b->max = ft_max_value(b);
		if (b->nb > 1)
			ft_up_max(b);
		ft_push_a(a, b);
	}
}

static void	ft_list_index(t_stack *a, int *list_index)
{
	int	i;
	int	j;

	i = 0;
	while (i < a->nb)
	{
		list_index[i] = 0;
		i++;
	}
	i = 0;
	while (i < a->nb)
	{
		j = 0;
		while (j < a->nb)
		{
			if (a->list[i] > a->list[j])
				(list_index[i])++;
			j++;
		}
		i++;
	}
}

int	ft_k_distribution_sort(t_stack *a)
{
	t_stack	b;
	int		*list_index;

	b.list = malloc(sizeof (int) * (a->nb));
	if (!(b.list))
		return (-1);
	b.nb = 0;
	list_index = malloc(sizeof (*list_index) * (a->nb));
	if (!list_index)
		return (-1);
	ft_list_index(a, list_index);
	ft_special_k(a, &b, list_index);
	free(list_index);
	free(b.list);
	return (0);
}
