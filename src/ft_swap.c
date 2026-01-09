/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:29:24 by julauren          #+#    #+#             */
/*   Updated: 2026/01/09 13:15:15 by julauren         ###   ########.fr       */
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
	if (a->nb < 2)
		return ;
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_swap_b(t_stack *b)
{
	if (b->nb < 2)
		return ;
	ft_swap(b);
	write(1, "sb\n", 3);
}

void	ft_swap_al(t_stack *a, int *list_index)
{
	int	tmp_index;

	if (a->nb < 2)
		return ;
	tmp_index = list_index[a->nb - 1];
	list_index[a->nb - 1] = list_index[a->nb - 2];
	list_index[a->nb - 2] = tmp_index;
	ft_swap(a);
	write(1, "sa\n", 3);
}

void	ft_both_swap(t_stack *a, t_stack *b, int *list_index)
{
	int	tmp_index;

	if (a->nb < 2 && b->nb < 2)
		return ;
	tmp_index = list_index[a->nb - 1];
	list_index[a->nb - 1] = list_index[a->nb - 2];
	list_index[a->nb - 2] = tmp_index;
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
