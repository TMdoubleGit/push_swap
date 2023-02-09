/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_strikes_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:15:37 by tmichel-          #+#    #+#             */
/*   Updated: 2022/12/30 18:27:49 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	rev_rot(t_pile *pile, char c)
{
	int	i;
	int	tmp;

	(void)c;
	if (!pile->size)
		return (1);
	i = pile->size - 1;
	tmp = *(pile->tab + i);
	while (i > 0)
	{
		*(pile->tab + i) = *(pile->tab + i - 1);
		i--;
	}
	*(pile->tab + 0) = tmp;
	return (1);
}

int	rrr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	if (!pile_a->size | !pile_b->size)
		return (1);
	i = pile_a->size - 1;
	tmp = *(pile_a->tab + i);
	while (i > 0)
	{
		*(pile_a->tab + i) = *(pile_a->tab + i - 1);
		i--;
	}
	*(pile_a->tab + 0) = tmp;
	i = pile_b->size - 1;
	tmp = *(pile_b->tab + i);
	while (i > 0)
	{
		*(pile_b->tab + i) = *(pile_b->tab + i - 1);
		i--;
	}
	*(pile_b->tab + 0) = tmp;
	return (1);
}

int	check_move(t_pile *pile_a, t_pile *pile_b, int i, char *move)
{
	if (ft_strcmp(move, "sa\n") == 0)
		i = swap(pile_a, 'a');
	else if (ft_strcmp(move, "sb\n") == 0)
		i = swap(pile_b, 'b');
	else if (ft_strcmp(move, "ss\n") == 0)
		i = ss(pile_a, pile_b);
	else if (ft_strcmp(move, "pa\n") == 0)
		i = push(pile_b, pile_a, 'a');
	else if (ft_strcmp(move, "pb\n") == 0)
		i = push(pile_a, pile_b, 'b');
	else if (ft_strcmp(move, "ra\n") == 0)
		i = rotate(pile_a, 'a');
	return (i);
}

int	check_move_others(t_pile *pile_a, t_pile *pile_b, int i, char *move)
{
	if (ft_strcmp(move, "rb\n") == 0)
		i = rotate(pile_b, 'b');
	else if (ft_strcmp(move, "rr\n") == 0)
		i = rr(pile_a, pile_b);
	else if (ft_strcmp(move, "rra\n") == 0)
		i = rev_rot(pile_a, 'a');
	else if (ft_strcmp(move, "rrb\n") == 0)
		i = rev_rot(pile_b, 'b');
	else if (ft_strcmp(move, "rrr\n") == 0)
		i = rrr(pile_a, pile_b);
	return (i);
}
