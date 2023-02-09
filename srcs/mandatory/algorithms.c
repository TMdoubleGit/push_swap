/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 17:09:58 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/04 13:50:15 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted_pile(t_pile *pile)
{
	int	i;

	if (pile->size == 0)
		return (0);
	i = -1;
	while (++i < pile->size - 1)
	{
		if (*(pile->tab + i) > *(pile->tab + i + 1))
			return (0);
	}
	if (i == pile->size - 1)
		return (1);
	return (0);
}

void	alg_three(t_pile *pile, char c)
{
	if (*(pile->tab + 0) > *(pile->tab + 1) && *(pile->tab + 1) > *(pile->tab
			+ 2))
	{
		swap(pile, c);
		rev_rot(pile, c);
	}
	if (*(pile->tab + 0) > *(pile->tab + 1) && *(pile->tab + 1) < *(pile->tab
			+ 2) && *(pile->tab + 0) < *(pile->tab + 2))
		swap(pile, c);
	if (*(pile->tab + 0) > *(pile->tab + 1) && *(pile->tab + 1) < *(pile->tab
			+ 2) && *(pile->tab + 0) > *(pile->tab + 2))
		rotate(pile, c);
	if (*(pile->tab + 0) < *(pile->tab + 1) && *(pile->tab + 1) > *(pile->tab
			+ 2) && *(pile->tab + 0) < *(pile->tab + 2))
	{
		swap(pile, c);
		rotate(pile, c);
	}
	if (*(pile->tab + 0) < *(pile->tab + 1) && *(pile->tab + 1) > *(pile->tab
			+ 2) && *(pile->tab + 0) > *(pile->tab + 2))
		rev_rot(pile, c);
}

void	alg_five(t_pile *pile_a, char a, t_pile *pile_b, char b)
{
	if (pile_a->size == 3)
	{
		alg_three(pile_a, a);
		return ;
	}
	ft_min_zero(pile_a, a);
	if (sorted_pile(pile_a) == 1)
		return ;
	push(pile_a, pile_b, b);
	if (pile_a->size == 3)
	{
		alg_three(pile_a, a);
		push(pile_b, pile_a, a);
		return ;
	}
	if (sorted_pile(pile_a) == 1)
		return ;
	ft_min_zero(pile_a, a);
	push(pile_a, pile_b, b);
	alg_three(pile_a, a);
	push(pile_b, pile_a, a);
	push(pile_b, pile_a, a);
}

void	alg_bigstack(t_pile *pile_a, char a, t_pile *pile_b, char b)
{
	int	i;
	int	j;
	int	k;

	while (pile_a->size != 3)
		push(pile_a, pile_b, b);
	alg_three(pile_a, a);
	while (pile_b->size > 0)
	{
		k = ft_find_next(pile_a, pile_b, ft_find_cheapest(pile_a, pile_b));
		i = ft_cost(pile_a, k);
		j = ft_cost(pile_b, ft_find_cheapest(pile_a, pile_b));
		if ((i >= 0 && j >= 0))
			loop_one(pile_a, pile_b, i, j);
		else if ((i < 0 && j < 0))
			loop_two(pile_a, pile_b, i, j);
		else
			loop_three(pile_a, pile_b, i, j);
		push(pile_b, pile_a, a);
	}
	ft_min_zero(pile_a, 'a');
}
