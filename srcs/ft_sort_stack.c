/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:46:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/02 17:11:31 by julauren         ###   ########.fr       */
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
	while (a->i - a->j == 1)
	{
		a->i = a->j;
		a->j = ft_max(a, a->i);
	}
	if (a->i == 0 && a->j == 0)
	{
		free(b.list);
		return (-1);
	}
	a->pivot = (a->i) / 2;
	if (a->i > a->pivot)
	{
		if (a->j > a->pivot)
		{
			while (a->i > a->j)
			{
				ft_rotate_a(a);
				(a->i)++;
				(a->j)++;
				if (a->i == a->nb)
					a->i = 0;
			}
			while (a->j < a->nb)
				ft_push_b(&b, a);
			ft_reverse_rotate_a(a);
			ft_push_a(a, &b);
		}
		else
		{

		}
	}
	else
	{
		if (a->j < a->pivot)
		{

		}
		else
		{

		}
	}
	free(b.list);
	return (0);
}
