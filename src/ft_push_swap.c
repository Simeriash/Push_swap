/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:14:12 by julauren          #+#    #+#             */
/*   Updated: 2025/12/13 17:06:15 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_quicksort(t_stack *a)
{
	a->max = ft_max(a, INT_MAX);
	if (a->max == 2)
		ft_rotate(a, 'a');
	if (a->max == 1)
		ft_reverse_rotate(a, 'a');
	if (a->list[a->nb - 1] > a->list[a->nb - 2])
		ft_swap_a(a);
}

int	main(int ac, char **av)
{
	t_stack	a;
	int		ctrl;

	a.list = NULL;
	if (ac == 1)
		return (0);
	ctrl = ft_make_list(ac, av, &a);
	if (ctrl == -2)
		write(2, "Error\n", 6);
	if (ctrl < 0)
	{
		if (a.list)
			free(a.list);
		return (0);
	}
	if (a.nb < 4)
		ft_quicksort(&a);
	else
		ft_sort_stack(&a);
	free(a.list);
	return (0);
}
