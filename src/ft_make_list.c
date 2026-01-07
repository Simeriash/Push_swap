/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:12:38 by julauren          #+#    #+#             */
/*   Updated: 2026/01/06 09:53:41 by julauren         ###   ########.fr       */
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
		if (!(ft_isdigit(str[i])))
			return (-2);
		while (ft_isdigit(str[i]) && str[i] != '\0')
			i++;
		if (!(ft_isdigit(str[i])) && !(ft_isspace(str[i]) || str[i] == '\0'))
			return (-2);
		count++;
	}
	return (count);
}

static int	ft_fill_in_stack(char **tab, t_stack *a, int *ctrl)
{
	int			i;
	static int	j;

	i = 0;
	*ctrl = 0;
	while (tab[i])
	{
		a->list[j] = ft_atoi_ps(tab[i], ctrl);
		if (*ctrl == 1)
		{
			while (tab[i])
			{
				free(tab[i]);
				i++;
			}
			free(tab);
			return (-2);
		}
		free(tab[i]);
		j++;
		i++;
	}
	free(tab);
	return (0);
}

static int	ft_fill_in_tab(int ac, char **av, t_stack *a)
{
	int		i;
	int		ctrl;
	char	**tab;

	i = 1;
	while (i < ac)
	{
		tab = ft_split_ps(av[i]);
		if (!tab)
			return (-1);
		if (ft_fill_in_stack(tab, a, &ctrl) < 0)
			return (-2);
		i++;
	}
	ctrl = ft_format_stack(a);
	if (ctrl < 0)
		return (ctrl);
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
	a->list = malloc(sizeof(int) * (a->nb));
	if (!(a->list))
		return (-1);
	ctrl = ft_fill_in_tab(ac, av, a);
	if (ctrl < 0)
		return (ctrl);
	return (0);
}
