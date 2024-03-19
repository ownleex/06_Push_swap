/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 17:55:57 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 16:51:07 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>

typedef struct s_stacks {
	t_list *a;
	t_list *b;
} t_stacks;

//ft_main.c
int     is_number(char *str);

//ft_little_sort.c
t_list	*find_max(t_list *stack);
void	sort_three(t_stacks *stacks);
int		count_elements(t_list *stack);
int		is_sorted(t_list *stack);
void	sort_stack(t_stacks *stacks);

//ft_big_sort.c
void	big_sort(t_stacks *stacks);

//ft_init_a_to_b.c
void	init_nodes_a(t_stacks *stacks);
void	current_index(t_list *stack);
void	set_target_a(t_stacks *stacks);
void	cost_analysis_a(t_stacks *stacks);
void	set_cheapest(t_list *stack);

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

#endif
