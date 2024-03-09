/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:55:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/08 22:19:02 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"

typedef struct s_stacks {
    t_list *a;
    t_list *b;
} t_stacks;

//ft_main.c
int     is_number(char *str);

//ft_swap.c
void	swap(t_list **stack);
void	sa(t_stacks *stacks);
void	sb(t_stacks *stacks);
void	ss(t_stacks *stacks);

//ft_push.c
void	push(t_list **src, t_list **dest);
void	pa(t_stacks *stacks);
void	pb(t_stacks *stacks);

//ft_rotate
void	rotate(t_list **stack);
void	ra(t_stacks *stacks);
void	rb(t_stacks *stacks);
void	rr(t_stacks *stacks);

//ft_reverse.c
void	reverse_rotate(t_list **stack);
void	rra(t_stacks *stacks);
void	rrb(t_stacks *stacks);
void	rrr(t_stacks *stacks);



void	print_stack_a(t_list *stack_a);
void	print_stack_b(t_list *stack_b);

#endif
