/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:46 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/19 14:41:23 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack_a(t_list *stack_a)
{
	t_list	*current;

	if (stack_a == NULL)
	{
		ft_printf("Pile a est vide.\n");
	}
	else
	{
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
	t_list	*current;

	if (stack_b == NULL)
	{
		ft_printf("Pile b est vide.\n");
	}
	else
	{
		ft_printf("Pile b:\n");
		current = stack_b;
		while (current != NULL)
		{
			ft_printf("%d\n", *(int *)current->content);
			current = current->next;
		}
	}
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
	char		**args; // Tableau pour les arguments après le split

	stacks.a = NULL;
	stacks.b = NULL;
	if (argc < 3 && argc != 2)
	{
		ft_printf("Usage: %s number1 number2 ...\n", argv[0]);
		return (1);
	}
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
	{
		args = argv + 1; // Utilisez argv directement, en sautant le nom du programme
		argc--; // Ajustez argc pour refléter le décalage
	}
	i = 0;
	while (args[i])
	{ // Continuez tant que l'élément courant du tableau d'arguments n'est pas NULL
		if (!is_number(args[i]))
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
		*value = ft_atoi(args[i]);
		ft_lstadd_back(&(stacks.a), ft_lstnew(value));
		i++;
	}
	sort_stack(&stacks);
	if (argc == 1)// Si ft_split a été utilisé
	{
		i = 0;
		while (args[i]) {
			free(args[i]);
			i++;
		}
		free(args);
	}
	ft_lstclear(&(stacks.a), free);
	ft_lstclear(&(stacks.b), free);
	return (0);
}
