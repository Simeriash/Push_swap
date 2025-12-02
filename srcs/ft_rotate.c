/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:14:56 by julauren          #+#    #+#             */
/*   Updated: 2025/12/02 14:18:28 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_stack *x)
{
	int	i;
	int	tmp;

	if (x->nb <= 1)
		return ;
	i = x->nb - 1;
	tmp = x->list[i];
	while (i > 0)
	{
		x->list[i] = x->list[i - 1];
		i--;
	}
	x->list[0] = tmp;
}

void	ft_rotate_a(t_stack *a)
{
	ft_rotate(a);
	write(1, "ra\n", 3);
}

void	ft_rotate_b(t_stack *b)
{
	ft_rotate(b);
	write(1, "rb\n", 3);
}

void	ft_both_rotate(t_stack *a, t_stack *b)
{
	ft_rotate(a);
	ft_rotate(b);
	write(1, "rr\n", 3);
}
