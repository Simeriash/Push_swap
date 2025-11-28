/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:12:38 by julauren          #+#    #+#             */
/*   Updated: 2025/11/28 14:28:22 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(const char *str, int i)
{
	if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		return (1);
	return (0);
}

static int	ft_atoi(const char *str, int *error)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	while (ft_isspace(str, i))
		i++;
	if (str[i] == '-')
		sign = -sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (num > INT_MAX || num < INT_MIN || ft_isdigit(str[i]))
		*error = 1;
	return (sign * num);
}

int	ft_make_list(int ac, char **av, t_stack *a)
{
	int	len;

	len = 0;
	a->list = malloc(sizeof(int) * ac);
	if (!(a->list))
		return (-1);
	return (len);
}
