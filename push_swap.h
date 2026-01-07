/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:34:44 by julauren          #+#    #+#             */
/*   Updated: 2025/12/21 14:02:16 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "src/libft/libft.h"

typedef struct s_stack	t_stack;
struct s_stack
{
	int	nb;
	int	*list;
	int	max;
	int	min;
	int	median;
};

int		main(int ac, char **av);
void	ft_swap_a(t_stack *a);
void	ft_swap_b(t_stack *b);
void	ft_swap_al(t_stack *a, int *list_index);
void	ft_both_swap(t_stack *a, t_stack *b, int *list_index);
void	ft_push_a(t_stack *a, t_stack *b);
void	ft_push_b(t_stack *b, t_stack *a);
void	ft_rotate_a(t_stack *a);
void	ft_rotate_b(t_stack *b);
void	ft_rotate_al(t_stack *a, int *list_index);
void	ft_both_rotate(t_stack *a, t_stack *b, int *list_index);
void	ft_reverse_rotate_a(t_stack *a);
void	ft_reverse_rotate_b(t_stack *b);
void	ft_reverse_rotate_al(t_stack *a, int *list_index);
void	ft_both_reverse_rotate(t_stack *a, t_stack *b, int *list_index);
int		ft_make_list(int ac, char **av, t_stack *a);
char	**ft_split_ps(const char *s);
int		ft_atoi_ps(const char *str, int *ctrl);
int		ft_format_stack(t_stack *a);
int		ft_k_distribution_sort(t_stack *a);
int		ft_max_value(t_stack *x);
int		ft_turkish_sort(t_stack *a);
int		ft_min(t_stack *x, int min);
int		ft_max(t_stack *x, int max);
void	ft_push_to_b(t_stack *a, t_stack *b);
void	ft_push_to_a(t_stack *a, t_stack *b, int len);

#endif
