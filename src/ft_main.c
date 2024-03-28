/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:46 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/27 12:06:17 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_duplicate(t_stacks *stacks)
{
	t_list	*current;
	t_list	*next;
	int		*current_val;
	int		*next_val;

	current = stacks->a;
	while (current != NULL && current->next != NULL)
	{
		current_val = (int *)current->content;
		next = current->next;
		while (next != NULL)
		{
			next_val = (int *)next->content;
			if (*current_val == *next_val)
				return (0);
			next = next->next;
		}
		current = current->next;
	}
	return (1);
}

int	free_all(t_stacks *stacks, char **args, int argc, int error)
{
	int		i;

	if (argc == 2)
	{
		i = 0;
		while (args[i])
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
	ft_lstclear(&(stacks->a), free);
	ft_lstclear(&(stacks->b), free);
	if (error)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	return (0);
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

int	parse_args(int argc, char **argv, t_stacks *stacks, char ***args)
{
	int		i;
	long	*value;

	if (argc == 2)
		*args = ft_split(argv[1], ' ');
	else
		*args = argv + 1;
	i = 0;
	while ((*args)[i])
	{
		if (!is_number((*args)[i]))
			return (0);
		value = malloc(sizeof(long));
		if (!value)
			return (0);
		*value = ft_atol((*args)[i]);
		if (*value > INT_MAX || *value < INT_MIN)
		{
			free(value);
			return (0);
		}
		ft_lstadd_back(&(stacks->a), ft_lstnew(value));
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	char		**args;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stacks.a = NULL;
	stacks.b = NULL;
	args = NULL;
	if (!parse_args(argc, argv, &stacks, &args))
	{
		free_all(&stacks, args, argc, 1);
		return (1);
	}
	if (!check_duplicate(&stacks))
	{
		free_all(&stacks, args, argc, 1);
		return (1);
	}
	sort_stack(&stacks);
	free_all(&stacks, args, argc, 0);
	return (0);
}
