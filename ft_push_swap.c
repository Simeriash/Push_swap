/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:14:12 by julauren          #+#    #+#             */
/*   Updated: 2025/11/29 17:01:46 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	int		len;

	a.list = NULL;
	if (ac == 1)
		return (0);
	len = ft_make_list(ac, av, &a);
	if (len == -2)
		write(2, "Error\n", 6);
	if (len < 0)
	{
		if (a.list)
			free(a.list);
		return (0);
	}
	printf("############\nlen:%d\n", len);
	free(a.list);
	return (0);
}
