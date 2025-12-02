/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:39:12 by julauren          #+#    #+#             */
/*   Updated: 2025/12/02 11:24:37 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_intlen(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*str;
	int		sign;
	int		i;

	sign = 0;
	if (n < 0)
		sign = 1;
	len = ft_intlen(n) + sign;
	str = ft_calloc(len + 1, sizeof (*str));
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	i = len - 1;
	while (i >= sign)
	{
		str[i] = (n % 10) * (!sign - sign) + 48;
		n = n / 10;
		i--;
	}
	return (str);
}
