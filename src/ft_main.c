/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayarmaya <ayarmaya@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 18:12:46 by ayarmaya          #+#    #+#             */
/*   Updated: 2024/03/05 03:41:38 by ayarmaya         ###   ########.fr       */
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
	int	i;
	int	*numbers;

	if (argc < 3)
	{
		ft_printf("Error\n");
		return (0);
	}
	numbers = (int *)malloc(sizeof(int) * argc - 1);
	if (!numbers)
		return (1);
	i = 0;
	while (i < argc -1)
	{
		if (!is_number(argv[i + 1]))
		{
			ft_printf("Error\n");
			free(numbers);
			return (0);
		}
		numbers[i] = ft_atoi(argv[i + 1]);
		ft_printf("%d\n", numbers[i]);
		i++;
	}
	// Utilisez maintenant le tableau `numbers` pour votre logique de tri...

	free(numbers);
	return (1);
}
