/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_strikes_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 16:15:37 by tmichel-          #+#    #+#             */
/*   Updated: 2022/12/30 17:57:33 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev_rot(t_pile *pile, char c)
{
	int	i;
	int	tmp;

	if (!pile->size)
		return ;
	i = pile->size - 1;
	tmp = *(pile->tab + i);
	while (i > 0)
	{
		*(pile->tab + i) = *(pile->tab + i - 1);
		i--;
	}
	*(pile->tab + 0) = tmp;
	ft_printf("rr%c\n", c);
}

void	rrr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	if (!pile_a->size || !pile_b->size)
		return ;
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
	ft_printf("rrr\n");
}
