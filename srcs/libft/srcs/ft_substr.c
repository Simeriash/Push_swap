/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:20:08 by julauren          #+#    #+#             */
/*   Updated: 2025/12/02 11:28:04 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	size_t	slen;
	char	*dest;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
		size = 0;
	else if (len > slen - start)
		size = slen - start;
	else
		size = len;
	dest = ft_calloc(size + 1, sizeof (*dest));
	if (!dest)
		return (NULL);
	i = 0;
	while (i < size && s[start + i] != '\0')
	{
		dest[i] = s[start + i];
		i++;
	}
	return (dest);
}
