/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 13:29:36 by julauren          #+#    #+#             */
/*   Updated: 2025/12/04 15:11:40 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_push_i(t_stack *i, t_stack *j)
{
	if (j->nb == 0)
		return ;
	i->list[i->nb] = j->list[j->nb - 1];
	(i->nb)++;
	(j->nb)--;
}

void	ft_push_a(t_stack *a, t_stack *b)
{
	ft_push_i(a, b);
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack *b, t_stack *a)
{
	ft_push_i(b, a);
	write(1, "pb\n", 3);
}
