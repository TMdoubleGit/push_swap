/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 11:58:17 by tmichel-          #+#    #+#             */
/*   Updated: 2022/12/30 17:46:18 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_max(int *tab, int a, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (a < *(tab + j))
			break ;
		j++;
	}
	if (j == size)
		return (1);
	else
		return (0);
}

int	ft_is_min(int *tab, int a, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (a > *(tab + j))
			break ;
		j++;
	}
	if (j == size)
		return (1);
	else
		return (0);
}

int	ft_find_min_index(t_pile *pile)
{
	int	i;

	i = 0;
	while (ft_is_min(pile->tab, *(pile->tab + i), pile->size) != 1)
		i++;
	return (i);
}

int	ft_find_max_index(t_pile *pile)
{
	int	i;

	i = 0;
	while (ft_is_max(pile->tab, *(pile->tab + i), pile->size) != 1)
		i++;
	return (i);
}

void	ft_min_zero(t_pile *pile, char a)
{
	int	i;

	i = ft_find_min_index(pile);
	if (i <= pile->size / 2)
		do_rotate(pile, a, i);
	else
	{
		while (i < pile->size)
		{
			rev_rot(pile, a);
			i++;
		}
	}
}
