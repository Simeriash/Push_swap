/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:14:12 by julauren          #+#    #+#             */
/*   Updated: 2025/11/28 13:34:25 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	a;
	int		len;

	if (ac == 1)
		return (0);
	len = ft_make_list(ac, av, &a);
	if (len == -1)
		return (0);
	printf("Hello\n");
	return (0);
}
