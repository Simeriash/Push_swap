/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:14:12 by julauren          #+#    #+#             */
/*   Updated: 2025/12/20 14:02:46 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	if (a.nb > 10)
		ft_k_distribution_sort(&a);
	else
		ft_turkish_sort(&a);
	free(a.list);
	return (0);
}
