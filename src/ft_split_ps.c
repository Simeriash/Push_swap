/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_ps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/29 17:30:42 by julauren          #+#    #+#             */
/*   Updated: 2025/12/19 16:26:32 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	ft_count_nb(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]))
			i++;
		if (str[i] == '\0')
			return (count);
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (ft_isdigit(str[i]))
			i++;
		count++;
	}
	return (count);
}

static void	ft_free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static char	**ft_tab(const char *s, char **tab, int nb_nb)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	end = 0;
	while (i < nb_nb)
	{
		start = end;
		while (s[start] == ' ' && s[start] != '\0')
			start++;
		end = start;
		while (s[end] != ' ' && s[end] != '\0')
			end++;
		tab[i] = ft_substr(s, start, end - start);
		if (!tab[i])
		{
			ft_free_tab(tab, i);
			return (NULL);
		}
		i++;
	}
	return (tab);
}

char	**ft_split_ps(const char *s)
{
	int		nb_nb;
	char	**tab;

	if (!s)
		return (NULL);
	nb_nb = ft_count_nb(s);
	tab = malloc(sizeof (*tab) * (nb_nb + 1));
	if (!tab)
		return (NULL);
	tab[nb_nb] = NULL;
	tab = ft_tab(s, tab, nb_nb);
	return (tab);
}
