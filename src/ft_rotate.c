/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:30:02 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/07 20:10:00 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (*stack && (*stack)->next)
	{
		first = *stack;
		last = *stack;
		while (last->next)
			last = last->next;
		*stack = first->next;
		first->next = NULL;
		last->next = first;
	}
}

void	ra(t_stacks *stacks)
{
	rotate(&(stacks->a));
}

void	rb(t_stacks *stacks)
{
	rotate(&(stacks->b));
}

void	rr(t_stacks *stacks)
{
	rotate(&(stacks->a));
	rotate(&(stacks->b));
}