/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:14:12 by julauren          #+#    #+#             */
/*   Updated: 2025/12/06 15:09:18 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_p(t_stack *a)
{
	int	i;

	i = a->nb - 1;
	printf("\n");
	while (i >= 0)
	{
		printf("%d ", a->list[i]);
		i--;
	}
	printf("\n");
	printf("\n");
	printf("len: %d\n\n", a->nb);
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
	ft_p(&a);
	ft_sort_stack(&a);
	ft_p(&a);
	free(a.list);
	return (0);
}
