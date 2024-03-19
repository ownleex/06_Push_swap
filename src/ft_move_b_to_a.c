/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:29:00 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 19:00:00 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_b_to_a(t_stacks *stacks)
{
	prep_for_push(stacks, &stacks->a, stacks->b->target_node, 'a');
	pa(stacks);
}
