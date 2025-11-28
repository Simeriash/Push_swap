/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:12:38 by julauren          #+#    #+#             */
/*   Updated: 2025/11/27 15:39:10 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_make_list(int ac, char **av, t_stack *a)
{
	int	len;

	len = 0;
	a->list = malloc(sizeof(int) * ac);
	if (!(a->list))
		return (-1);
	return (len);
}
