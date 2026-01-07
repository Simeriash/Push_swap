/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:29:24 by julauren          #+#    #+#             */
/*   Updated: 2025/12/20 13:17:53 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack *x)
{
	int	tmp;

	tmp = x->list[x->nb - 1];
	x->list[x->nb - 1] = x->list[x->nb - 2];
	x->list[x->nb - 2] = tmp;
}

void	ft_swap_a(t_stack *a)
{
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack *b)
{
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_swap_al(t_stack *a, int *list_index)
{
	int	tmp;
	int	tmp_index;

	tmp = a->list[a->nb - 1];
	tmp_index = list_index[a->nb - 1];
	a->list[a->nb - 1] = a->list[a->nb - 2];
	a->list[a->nb - 2] = tmp;
	list_index[a->nb - 1] = list_index[a->nb - 2];
	list_index[a->nb - 2] = tmp_index;
	write(1, "sa\n", 3);
}

void	ft_both_swap(t_stack *a, t_stack *b, int *list_index)
{
	int	tmp;
	int	tmp_index;

	tmp = a->list[a->nb - 1];
	tmp_index = list_index[a->nb - 1];
	a->list[a->nb - 1] = a->list[a->nb - 2];
	a->list[a->nb - 2] = tmp;
	list_index[a->nb - 1] = list_index[a->nb - 2];
	list_index[a->nb - 2] = tmp_index;
	ft_swap(b);
	write(1, "ss\n", 3);
}
