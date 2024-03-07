/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:46 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/07 01:15:47 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		i;
	t_list	*stack = NULL;
	int		*value;

	if (argc < 3)
	{
		ft_printf("Usage: %s number1 number2 ...\n", argv[0]);
		return (0);
	}
	i = 0;
	while (++i < argc)
	{
		if (!is_number(argv[i]))
		{
			ft_printf("Error\n");
			ft_lstclear(&stack, free);
			return (0);
		}
		value = malloc(sizeof(int));
		if (!value)
		{
			ft_printf("Malloc failed\n");
			ft_lstclear(&stack, free);
			return (1);
		}
		*value = ft_atoi(argv[i]);
		ft_lstadd_back(&stack, ft_lstnew(value));
	}
	// Parcourir et imprimer chaque nombre
	while (stack)
	{
		ft_printf("%d\n", *(int *)stack->content);
		stack = stack->next;
	}
	ft_lstclear(&stack, free);
	return (1);
}
