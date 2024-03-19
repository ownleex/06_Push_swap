/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:27:39 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 18:59:15 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cheapest(t_list *stack)
{
	long	cheapest_value;
	t_list	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	cost_analysis_a(t_stacks *stacks)
{
	int		len_a;
	int		len_b;

	len_a = count_elements(stacks->a);
	len_b = count_elements(stacks->b);
	while (stacks->a)
	{
		stacks->a->push_cost = stacks->a->index;
		if (!(stacks->a->above_median))
			stacks->a->push_cost = len_a - (stacks->a->index);
		if (stacks->a->target_node->above_median)
			stacks->a->push_cost += stacks->a->target_node->index;
		else
			stacks->a->push_cost += len_b - stacks->a->target_node->index;
		stacks->a = stacks->a->next;
	}
}

void	set_target_a(t_stacks *stacks)
{
	t_list	*current_b;
	t_list	*target_node;
	long	best_index;

	while (stacks->a)
	{
		best_index = LONG_MIN;
		current_b = stacks->b;
		while (current_b)
		{
			if (current_b->content < stacks->a->content && \
			*(int *)current_b->content > best_index)
			{
				best_index = *(int *)current_b->content;
				target_node = current_b;
			}
			current_b = current_b->next;
		}
		if (best_index == LONG_MIN)
			stacks->a->target_node = find_max(stacks->b);
		else
			stacks->a->target_node = target_node;
		stacks->a = stacks->a->next;
	}
}

void	current_index(t_list *stack)
{
	int		i;
	int		median;

	i = 0;
	if (!stack)
		return ;
	median = count_elements(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	init_nodes_a(t_stacks *stacks)
{
	current_index(stacks->a);
	current_index(stacks->b);
	set_target_a(stacks);
	cost_analysis_a(stacks);
	set_cheapest(stacks->a);
}
