/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:14:22 by julauren          #+#    #+#             */
/*   Updated: 2025/12/09 15:08:29 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_reverse_rot(t_stack *x)
{
	int	i;
	int	tmp;
	int	end;

	if (x->nb <= 1)
		return ;
	tmp = x->list[0];
	i = 0;
	end = x->nb - 1;
	while (i < end)
	{
		x->list[i] = x->list[i + 1];
		i++;
	}
	x->list[end] = tmp;
}

void	ft_reverse_rotate(t_stack *x, char c)
{
	ft_reverse_rot(x);
	if (c == 'a')
		write(1, "rra\n", 4);
	else
		write(1, "rrb\n", 4);
}

void	ft_both_reverse_rotate(t_stack *a, t_stack *b)
{
	ft_reverse_rot(a);
	ft_reverse_rot(b);
	write(1, "rrr\n", 4);
}
