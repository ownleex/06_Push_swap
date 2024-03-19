/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:39:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 14:44:49 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stack)
{
	int	max;
	int	index;
	int	max_index;
	t_list	*current;

	max = *(int *)stack->content;
	max_index = 0;
	index = 0;
	current = stack;
	while (current)
	{
		if (*(int *)current->content > max)
		{
			max = *(int *)current->content;
			max_index = index;
		}
		index++;
		current = current->next;
	}
	return (max_index);
}

void	sort_three(t_stacks *stacks)
{
	int	max_index;

	max_index = find_max(stacks->a);
	if (max_index == 0)
		ra(stacks);
	else if (max_index == 1)
		rra(stacks);
	if (*(int *)stacks->a->content > *(int *)stacks->a->next->content)
		sa(stacks);
}

int	count_elements(t_list *stack)
{
	int count;

	count = 0;
	while (stack)
	{
		count++;
		stack = stack->next;
	}
	return (count);
}

int	is_sorted(t_list *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_stack(t_stacks *stacks)
{
	if (!is_sorted(stacks->a))
	{
		if (count_elements(stacks->a) == 2)
			sa(stacks);
		else if (count_elements(stacks->a) == 3)
			sort_three(stacks);
		else
			big_sort(stacks);
	}
}
