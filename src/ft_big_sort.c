/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:25 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 18:57:54 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list *head)
{
	t_list	*min;
	t_list	*current;

	min = head;
	current = head->next;
	while (current != NULL)
	{
		if (*((int *)current->content) < *((int *)min->content))
			min = current;
		current = current->next;
	}
	return (min);
}

void	min_on_top(t_stacks *stacks, t_list **a)
{
	while ((*a)->content != find_min(*a)->content)
	{
		if (find_min(*a)->above_median)
			ra(stacks);
		else
			rra(stacks);
	}
}

void	big_sort(t_stacks *stacks)
{
	int		len_a;

	len_a = count_elements(stacks->a);
	if (len_a-- > 3 && !is_sorted(stacks->a))
		pb(stacks);
	if (len_a-- > 3 && !is_sorted(stacks->a))
		pb(stacks);
	while (len_a-- > 3 && !is_sorted(stacks->a))
	{
		init_nodes_a(stacks);
		move_a_to_b(stacks);
	}
	sort_three(stacks);
	while (stacks->b)
	{
		init_nodes_b(stacks);
		move_b_to_a(stacks);
	}
	current_index(stacks->a);
	min_on_top(stacks, &stacks->a);
}
