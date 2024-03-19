/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 14:27:39 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 14:54:41 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    big_sort(t_stacks *stacks)
{
	int     len_a;

	len_a = count_elements(stacks->a);
	if (len_a-- > 3 && !is_sorted(stacks->a))
		pb(stacks);
	if (len_a-- > 3 && !is_sorted(stacks->a))
		pb(stacks);
	while (len_a-- > 3 && !is_sorted(stacks->a))
	{
		
	}
}