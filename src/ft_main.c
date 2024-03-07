/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:46 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/07 20:24:56 by ayarmaya         ###   ########.fr       */
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

void	print_stack_a(t_list *stack_a)
{
	if (stack_a == NULL)
	{
		ft_printf("Pile a est vide.\n");
	}
	else
	{
		t_list	*current;

		ft_printf("Pile a:\n");
		current = stack_a;
		while (current != NULL)
		{
			ft_printf("%d\n", *(int *)current->content);
			current = current->next;
		}
	}
}

void	print_stack_b(t_list *stack_b)
{
	if (stack_b == NULL)
	{
		ft_printf("Pile b est vide.\n");
	}
	else
	{
		t_list	*current;

		ft_printf("Pile b:\n");
		current = stack_b;
		while (current != NULL)
		{
			ft_printf("%d\n", *(int *)current->content);
			current = current->next;
		}
	}
}

int	main(int argc, char **argv)
{
	int			i;
	t_stacks	stacks;
	int			*value;

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc < 3)
	{
		ft_printf("Usage: %s number1 number2 ...\n", argv[0]);
		return (1);
	}
	i = 0;
	while (++i < argc)
	{
		if (!is_number(argv[i]))
		{
			ft_printf("Error\n");
			ft_lstclear(&(stacks.a), free);
			ft_lstclear(&(stacks.b), free);
			return (1);
		}
		value = malloc(sizeof(int));
		if (!value)
		{
			ft_printf("Malloc failed\n");
			ft_lstclear(&(stacks.a), free);
			ft_lstclear(&(stacks.b), free);
			return (1);
		}
		*value = ft_atoi(argv[i]);
		ft_lstadd_back(&(stacks.a), ft_lstnew(value));
	}
	print_stack_a(stacks.a);
	print_stack_b(stacks.b);
	ft_lstclear(&(stacks.a), free);
	ft_lstclear(&(stacks.b), free);
	return (0);
}
