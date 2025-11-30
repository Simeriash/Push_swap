/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:14:12 by julauren          #+#    #+#             */
/*   Updated: 2025/11/30 17:21:33 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	free(a.list);
	return (0);
}
