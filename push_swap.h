/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:34:44 by julauren          #+#    #+#             */
/*   Updated: 2025/12/02 16:34:40 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>		//A EFFACER !!!
# include "srcs/libft/libft.h"

typedef struct s_stack	t_stack;
struct s_stack
{
	int	nb;
	int	*list;
	int	i;
	int	j;
	int	pivot;
};

typedef struct s_index	t_index;
struct s_index
{
	int	i;
	int	ctrl;
};

int		main(int ac, char **av);
void	ft_swap_a(t_stack *a);
void	ft_swap_b(t_stack *b);
void	ft_both_swap(t_stack *a, t_stack *b);
void	ft_push_a(t_stack *a, t_stack *b);
void	ft_push_b(t_stack *b, t_stack *a);
void	ft_rotate_a(t_stack *a);
void	ft_rotate_b(t_stack *b);
void	ft_both_rotate(t_stack *a, t_stack *b);
void	ft_reverse_rotate_a(t_stack *a);
void	ft_reverse_rotate_b(t_stack *b);
void	ft_both_reverse_rotate(t_stack *a, t_stack *b);
int		ft_make_list(int ac, char **av, t_stack *a);
char	**ft_split_ps(const char *s);
int		ft_atoi_ps(const char *str, int *ctrl);
int		ft_format_stack(t_stack *a);
int		ft_sort_stack(t_stack *a);

#endif
