/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:46 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/10 04:27:33 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	sort_stack(t_stacks *stacks)
{
	int		min, index, size;

	while (ft_lstsize(stacks->a) > 0)
	{
		t_list	*tmp = stacks->a;
		min = *(int *)tmp->content;
		index = 0;
		size = ft_lstsize(stacks->a);
		for (int i = 0; i < size; i++)
		{
			if (*(int *)tmp->content < min)
			{
				min = *(int *)tmp->content;
				index = i;
			}
			tmp = tmp->next;
		}
		if (index <= size / 2)
			while (index-- > 0)
				ra(stacks); // Tourner A jusqu'à ce que min soit en haut
		else
			while (index++ < size)
				rra(stacks); // Tourner A dans le sens inverse si plus court
		pb(stacks); // Pousser l'élément min sur B
	}
	while (ft_lstsize(stacks->b) > 0)
		pa(stacks); // Remettre tous les éléments sur A
}

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
			write(2, "Error\n", 6);
			ft_lstclear(&(stacks.a), free);
			ft_lstclear(&(stacks.b), free);
			return (1);
		}
		value = malloc(sizeof(int));
		if (!value)
		{
			write(2, "Error\n", 6);
			ft_lstclear(&(stacks.a), free);
			ft_lstclear(&(stacks.b), free);
			return (1);
		}
		*value = ft_atoi(argv[i]);
		ft_lstadd_back(&(stacks.a), ft_lstnew(value));
	}
	//print_stack_a(stacks.a);
	//print_stack_b(stacks.b);
	sort_stack(&stacks);
	//print_stack_a(stacks.a);
	//print_stack_b(stacks.b);
	ft_lstclear(&(stacks.a), free);
	ft_lstclear(&(stacks.b), free);
	return (0);
}
