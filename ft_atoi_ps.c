/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 16:14:38 by julauren          #+#    #+#             */
/*   Updated: 2025/11/29 16:16:49 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_isspace_sign(const char *str, int *i, int *sign)
{
	while ((str[*i] >= 9 && str[*i] <= 13) || str[*i] == 32)
		(*i)++;
	if (str[*i] == '-')
		*sign = -(*sign);
	if (str[*i] == '-' || str[*i] == '+')
		(*i)++;
}

int	ft_atoi_ps(const char *str, int *ctrl)
{
	int		i;
	long	num;
	int		sign;

	i = 0;
	num = 0;
	sign = 1;
	ft_isspace_sign(str, &i, &sign);
	while (ft_isdigit(str[i]))
	{
		if (num > INT_MAX || num < INT_MIN)
			break ;
		num = num * 10 + str[i] - 48;
		i++;
	}
	if (num > INT_MAX || num < INT_MIN || (!(ft_isdigit(str[i]))
			&& !(str[i] == ' ' || str[i] == '\0')))
		*ctrl = 1;
	return (sign * num);
}
