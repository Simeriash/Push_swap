/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:29:24 by julauren          #+#    #+#             */
/*   Updated: 2025/12/02 14:18:53 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_swap(t_stack *x)
{
	int	tmp;

	if (x->nb <= 1)
		return ;
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

void	ft_both_swap(t_stack *a, t_stack *b)
{
	ft_swap(a);
	ft_swap(b);
	write(1, "ss\n", 3);
}
