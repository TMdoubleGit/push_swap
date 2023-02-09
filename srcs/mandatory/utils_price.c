/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_price.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:42:19 by tmichel-          #+#    #+#             */
/*   Updated: 2022/12/28 10:52:10 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int a)
{
	if (a < 0)
		a *= -1;
	return (a);
}

int	ft_cost(t_pile *pile, int a)
{
	int	i;

	if (a <= pile->size / 2)
		i = a;
	else
		i = a - pile->size;
	return (i);
}

int	ft_totalcost(int a, int b)
{
	if ((a > 0 && b > 0) || (a < 0 && b < 0))
	{
		if (ft_abs(a) >= ft_abs(b))
			return (ft_abs(a));
		else
			return (ft_abs(b));
	}
	return (ft_abs(a) + ft_abs(b));
}

int	ft_find_next(t_pile *pile_a, t_pile *pile_b, int a)
{
	int	i;
	int	j;

	j = ft_find_max_index(pile_a);
	if (ft_is_max(pile_a->tab, *(pile_b->tab + a), pile_a->size) == 1)
		return (ft_find_min_index(pile_a));
	i = -1;
	while (++i < pile_a->size)
		if (*(pile_a->tab + i) > *(pile_b->tab + a)
			&& *(pile_a->tab + j) > *(pile_a->tab + i))
			j = i;
	return (j);
}

int	ft_find_cheapest(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	j;
	int	k;
	int	hold;
	int	tmp;

	i = -1;
	j = 0;
	k = ft_find_next(pile_a, pile_b, 0);
	hold = ft_totalcost(ft_cost(pile_b, 0), ft_cost(pile_a, k));
	while (++i < pile_b->size)
	{
		k = ft_find_next(pile_a, pile_b, i);
		tmp = ft_totalcost(ft_cost(pile_b, i), ft_cost(pile_a, k));
		if (tmp < hold)
		{
			hold = tmp;
			j = i;
		}
	}
	return (j);
}
