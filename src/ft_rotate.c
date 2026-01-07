/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 16:14:56 by julauren          #+#    #+#             */
/*   Updated: 2025/12/21 13:59:27 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_rotate(t_stack *x)
{
	int	i;
	int	tmp;

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

void	ft_rotate_al(t_stack *a, int *list_index)
{
	int	i;
	int	tmp;
	int	tmp_index;

	i = a->nb - 1;
	tmp = a->list[i];
	tmp_index = list_index[i];
	while (i > 0)
	{
		a->list[i] = a->list[i - 1];
		list_index[i] = list_index[i - 1];
		i--;
	}
	a->list[0] = tmp;
	list_index[0] = tmp_index;
	write(1, "ra\n", 3);
}

void	ft_both_rotate(t_stack *a, t_stack *b, int *list_index)
{
	int	i;
	int	tmp;
	int	tmp_index;

	i = a->nb - 1;
	tmp = a->list[i];
	tmp_index = list_index[i];
	while (i > 0)
	{
		a->list[i] = a->list[i - 1];
		list_index[i] = list_index[i - 1];
		i--;
	}
	a->list[0] = tmp;
	list_index[0] = tmp_index;
	ft_rotate(b);
	write(1, "rr\n", 3);
}
