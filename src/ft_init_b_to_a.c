/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:16:12 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 19:39:59 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stacks *stacks)
{
	t_list	*current_a;
	t_list	*target_node;
	long	best_index;

	while (stacks->b)
	{
		best_index = LONG_MIN;
		current_a = stacks->a;
		while (current_a)
		{
			if (current_a->content < stacks->b->content && \
			*(int *)current_a->content > best_index)
			{
				best_index = *(int *)current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == LONG_MIN)
			stacks->b->target_node = find_max(stacks->a);
		else
			stacks->b->target_node = target_node;
		stacks->b = stacks->b->next;
	}
}

void	init_nodes_b(t_stacks *stacks)
{
	current_index(stacks->a);
	current_index(stacks->b);
	set_target_a(stacks);
}
