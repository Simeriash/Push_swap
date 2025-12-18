/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:12:38 by julauren          #+#    #+#             */
/*   Updated: 2025/12/18 17:16:41 by julauren         ###   ########.fr       */
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
		while (ft_isspace(str[i]) && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (count);
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (!(ft_isdigit(str[i])))			// IF ??
			return (-2);
		while (ft_isdigit(str[i]) && str[i] != '\0')
			i++;
		if (!(ft_isdigit(str[i])) && !(ft_isspace(str[i]) || str[i] == '\0'))
			return (-2);
		count++;
	}
	return (count);
}

static int	ft_fill_in_stack(char **tab, t_stack *a)
{
	t_index		index;
	static int	j;

	index.i = 0;
	index.ctrl = 0;
	while (tab[index.i])
	{
		a->list[j] = ft_atoi_ps(tab[index.i], &index.ctrl);
		if (index.ctrl == 1)
		{
			j = index.i;
			while (tab[j])
			{
				free(tab[j]);
				j++;
			}
			free(tab);
			return (-2);
		}
		free(tab[index.i]);
		j++;
		(index.i)++;
	}
	free(tab);
	return (0);
}

static int	ft_fill_in_tab(int ac, char **av, t_stack *a)
{
	t_index	index;
	char	**tab;

	index.i = 1;
	while (index.i < ac)
	{
		tab = ft_split_ps(av[index.i]);
		if (!tab)
			return (-1);
		index.ctrl = ft_fill_in_stack(tab, a);
		if (index.ctrl < 0)
			return (-2);
		(index.i)++;
	}
	index.ctrl = ft_format_stack(a);
	if (index.ctrl < 0)
		return (index.ctrl);
	return (0);
}

int	ft_make_list(int ac, char **av, t_stack *a)
{
	int	ctrl;
	int	i;

	a->nb = 0;
	i = 1;
	while (i < ac)
	{
		ctrl = ft_count_nb(av[i]);
		if (ctrl <= 0)
			return (-2);
		(a->nb) += ctrl;
		i++;
	}
	if (a->nb == 1)
		return (-1);
	a->list = malloc(sizeof(int) * (a->nb));
	if (!(a->list))
		return (-1);
	ctrl = ft_fill_in_tab(ac, av, a);
	if (ctrl < 0)
		return (ctrl);
	return (0);
}
