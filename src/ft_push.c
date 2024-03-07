/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 14:15:25 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/07 14:27:24 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_list **src, t_list **dest)
{
	t_list	*first;

	if (*src)
	{
		first = *src;
		*src = (*src)->next;
		first->next = *dest;
		*dest = first;
	}
}

void	pa(t_list **a, t_list **b)
{
	push(b, a);
}

void	pb(t_list **a, t_list **b)
{
	push(a, b);
}
