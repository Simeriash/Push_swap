/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julauren <julauren@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:34:44 by julauren          #+#    #+#             */
/*   Updated: 2025/11/27 13:33:08 by julauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>		//A EFFACER !!!

typedef struct s_stack	t_stack;
struct s_stack
{
	int	nb;
	int	*list;
};

//LIBFT
size_t	ft_strlen(const char *s);

//PUSH_SWAP
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

#endif
