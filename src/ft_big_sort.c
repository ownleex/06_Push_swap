/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_big_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:15:25 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 17:05:35 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_stacks *stacks)
{
	int     len_a;

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
    /*
	while (stacks->b)
	{
		init_nodes_b(stacks);
		move_b_to_a(stacks);
	}
	current_index(stacks->a);
	min_on_top(stacks->a);
    */
}
