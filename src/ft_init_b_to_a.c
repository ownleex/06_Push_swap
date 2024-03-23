/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:16:12 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/23 01:22:58 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stacks *stacks)
{
	t_list	*current_a;
	t_list	*current_b;
	t_list	*target_node;
	int		best_index;

	current_b = stacks->b;
	while (current_b)
	{
		best_index = INT_MIN;
		current_a = stacks->a;
		target_node = NULL;
		while (current_a)
		{
			if (*(int *)current_a->content < *(int *)current_b->content && \
			*(int *)current_a->content > best_index)
			{
				best_index = *(int *)current_a->content;
				target_node = current_a;
			}
			current_a = current_a->next;
		}
		if (best_index == INT_MIN)
			current_b->target_node = find_max(stacks->a);
		else
			current_b->target_node = target_node;
		current_b = current_b->next;
	}
}

void	init_nodes_b(t_stacks *stacks)
{
	current_index(stacks->a);
}
