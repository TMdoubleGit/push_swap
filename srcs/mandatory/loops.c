/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:53:38 by tmichel-          #+#    #+#             */
/*   Updated: 2022/12/27 18:39:40 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	do_rotate(t_pile *pile, char a, int i)
{
	while (i > 0)
	{
		rotate(pile, a);
		i--;
	}
}

void	do_rev_rot(t_pile *pile, char a, int i)
{
	while (i > 0)
	{
		rev_rot(pile, a);
		i--;
	}
}

void	loop_one(t_pile *pile_a, t_pile *pile_b, int i, int j)
{
	int	k;

	if (i >= j)
	{
		k = i - j;
		while (j > 0)
		{
			rr(pile_a, pile_b);
			j--;
		}
		do_rotate(pile_a, 'a', k);
	}
	else
	{
		k = j - i;
		while (i > 0)
		{
			rr(pile_a, pile_b);
			i--;
		}
		do_rotate(pile_b, 'b', k);
	}
}

void	loop_two(t_pile *pile_a, t_pile *pile_b, int i, int j)
{
	int	k;

	i = ft_abs(i);
	j = ft_abs(j);
	if (i >= j)
	{
		k = i - j;
		while (j > 0)
		{
			rrr(pile_a, pile_b);
			j--;
		}
		do_rev_rot(pile_a, 'a', k);
	}
	else
	{
		k = j - i;
		while (i > 0)
		{
			rrr(pile_a, pile_b);
			i--;
		}
		do_rev_rot(pile_b, 'b', k);
	}
}

void	loop_three(t_pile *pile_a, t_pile *pile_b, int i, int j)
{
	if (i >= 0)
		do_rotate(pile_a, 'a', i);
	else
	{
		while (i < 0)
		{
			rev_rot(pile_a, 'a');
			i++;
		}
	}
	if (j >= 0)
		do_rotate(pile_b, 'b', j);
	else
	{
		while (j < 0)
		{
			rev_rot(pile_b, 'b');
			j++;
		}
	}
}
