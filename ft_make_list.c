/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 15:12:38 by julauren          #+#    #+#             */
/*   Updated: 2025/11/30 17:39:47 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_count_nb(const char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' && str[i] != '\0')
			i++;
		if (str[i] == '\0')
			return (count);
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (!(ft_isdigit(str[i])))
			return (-2);
		while (ft_isdigit(str[i]) && str[i] != '\0')
			i++;
		if (!(ft_isdigit(str[i])) && !(str[i] == ' ' || str[i] == '\0'))
			return (-2);
		count++;
	}
	return (count);
}

static void	ft_free_tab(char **tab, int n)
{
	int	i;

	i = 0;
	while (i <= n)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static int	ft_fill_in_stack(int ac, char ** av, t_stack *a)
{
	int		i;
	int		j;
	int		k;
	int		ctrl;
	char	**tab;

	ctrl = 0;
	i = 1;
	k = 0;
	while (i < ac)
	{
		tab = ft_split_ps(av[i]);
		if (!tab)
			return (-1);
		j = 0;
		while (tab[j])
		{
			a->list[k] = ft_atoi_ps(tab[j], &ctrl);
			if (ctrl == 1)
			{
				ft_free_tab(tab, j);
				return (-2);
			}
			free(tab[j]);
			k++;
			j++;
		}
		free(tab);
		i++;
	}
	return (0);
}

static void	ft_print(t_stack *a, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		printf("%d ", a->list[i]);
		i++;
	}
	printf("\n");
}

int	ft_make_list(int ac, char **av, t_stack *a)
{
	int	len;
	int	ctrl;
	int	i;
	//int	j;
	//int	k;
	//char	**tab;

	len = 0;
	i = 1;
	while (i < ac)
	{
		ctrl = ft_count_nb(av[i]);
		if (ctrl <= 0)
			return (-2);
		len += ctrl;
		i++;
	}
	a->list = malloc(sizeof(int) * len);
	if (!(a->list))
		return (-1);
	ctrl = ft_fill_in_stack(ac, av, a);
	if (ctrl < 0)
		return (ctrl);
	ft_print(a, len);
	// i = 1;
	// k = 0;
	// ctrl = 0;
	// while (i < ac)
	// {
	// 	tab = ft_split_ps(av[i]);
	// 	if (!tab)
	// 		return (-1);
	// 	j = 0;
	// 	while (tab[j])
	// 	{
	// 		a->list[k] = ft_atoi_ps(tab[j], &ctrl);
	// 		free(tab[j]);
	// 		k++;
	// 		j++;
	// 	}
	// 	free(tab);
	// 	i++;
	// }
	return (0);
}
//RECHERCHER LES DOUBLONS
