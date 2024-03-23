/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:46 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/23 01:51:28 by ayarmaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_stacks *stacks, char **args, int argc, char c)
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
	if (c == '1')
		write(2, "Error\n", 6);
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
	char		**args;

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
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		if (!is_number(args[i]))
		{
			free_all(&stacks, args, argc, '1');
			return (1);
		}
		value = malloc(sizeof(int));
		if (!value)
		{
			free_all(&stacks, args, argc, '1');
			return (1);
		}
		*value = ft_atoi(args[i]);
		ft_lstadd_back(&(stacks.a), ft_lstnew(value));
		i++;
	}
	sort_stack(&stacks);
	free_all(&stacks, args, argc, '0');
	return (0);
}
