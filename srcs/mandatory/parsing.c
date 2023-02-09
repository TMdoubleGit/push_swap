/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 16:28:27 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/03 12:07:22 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_error(char *err, int *tab)
{
	ft_putstr_fd(err, 2);
	free(tab);
	exit(0);
}

int	ft_double(int *tab, int size)
{
	int	i;
	int	j;

	i = -1;
	if (size == 0)
		return (0);
	while (++i < size)
	{
		j = i;
		while (++j < size)
		{
			if (*(tab + i) == *(tab + j))
				return (0);
		}
	}
	return (1);
}

void	ft_number(int ac, char **av, int *tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (++i < ac)
	{
		while (av[i][j] != '\0')
		{
			while (av[i][j] == ' ')
				j++;
			if ((av[i][j] == '-' && av[i][j - 1] != '-' && j == 0) ||
				(av[i][j] == '+' && av[i][j - 1] != '+' && j == 0))
				j++;
			if (ft_isdigit(av[i][j]) == 1)
			{
				j++;
				while (av[i][j] == ' ')
					j++;
			}
			else
				ft_error("Error\n", tab);
		}
		j = 0;
	}
}

int	*parse_args(int ac, char **av, int *tab)
{
	int	i;
	int	j;

	ft_number(ac, av, tab);
	i = 0;
	j = 1;
	while (i < ac && *(av + j) != (void *)0)
	{
		*(tab + i) = ft_atoi_long(*(av + j));
		if (ft_atoi_long(*(av + j)) > 2147483647
			|| ft_atoi_long(*(av + j)) < -2147483648)
			ft_error("Error\n", tab);
		i++;
		j++;
	}
	if (ft_double(tab, ac - 1) == 0)
		ft_error("Error\n", tab);
	return (tab);
}
