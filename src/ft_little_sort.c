/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_little_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:39:43 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 18:59:34 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*max_node;
	int		max;

	if (!stack)
		return (NULL);
	max = *(int *)stack->content;
	max_node = stack;
	while (stack)
	{
		if (*(int *)stack->content > max)
		{
			max = *(int *)stack->content;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

void	sort_three(t_stacks *stacks)
{
	t_list	*max_node;

	max_node = find_max(stacks->a);
	if (max_node == stacks->a)
		ra(stacks);
	else if (max_node == stacks->a->next)
		rra(stacks);
	if (*(int *)stacks->a->content > *(int *)stacks->a->next->content)
		sa(stacks);
}

int	count_elements(t_list *stack)
{
	int		count;

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
