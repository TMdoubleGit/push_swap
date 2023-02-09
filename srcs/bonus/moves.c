/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:29:31 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/02 12:10:10 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	swap(t_pile *pile, char c)
{
	int	i;
	int	tmp;

	(void)c;
	i = 0;
	if (!pile->size)
		return (1);
	tmp = *(pile->tab + 0);
	*(pile->tab + 0) = *(pile->tab + 1);
	*(pile->tab + 1) = tmp;
	return (1);
}

int	ss(t_pile *pile_a, t_pile *pile_b)
{
	int	tmp;

	if (pile_a->size > 1)
	{
		tmp = *(pile_a->tab + 0);
		*(pile_a->tab + 0) = *(pile_a->tab + 1);
		*(pile_a->tab + 1) = tmp;
	}
	if (pile_b->size > 1)
	{
		tmp = *(pile_b->tab + 0);
		*(pile_b->tab + 0) = *(pile_b->tab + 1);
		*(pile_b->tab + 1) = tmp;
	}
	return (1);
}

int	push(t_pile *src, t_pile *dst, char c)
{
	int	i;
	int	j;
	int	tmp;

	(void)c;
	if (!src->size)
		return (1);
	src->size--;
	dst->size++;
	j = dst->size;
	tmp = *(dst->tab + 0);
	*(dst->tab + 0) = *(src->tab + 0);
	while (--j > 1)
		*(dst->tab + j) = *(dst->tab + j - 1);
	i = -1;
	while (++i < src->size)
		*(src->tab + i) = *(src->tab + i + 1);
	*(dst->tab + 1) = tmp;
	return (1);
}

int	rotate(t_pile *pile, char c)
{
	int	i;
	int	tmp;

	(void)c;
	if (!pile->size)
		return (1);
	i = 0;
	tmp = *(pile->tab + 0);
	*(pile->tab + 0) = *(pile->tab + 1);
	while (++i < pile->size - 1)
		*(pile->tab + i) = *(pile->tab + i + 1);
	*(pile->tab + pile->size - 1) = tmp;
	return (1);
}

int	rr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	if (!pile_a->size | !pile_b->size)
		return (1);
	i = 0;
	tmp = *(pile_a->tab + 0);
	*(pile_a->tab + 0) = *(pile_a->tab + 1);
	while (++i < pile_a->size - 1)
		*(pile_a->tab + i) = *(pile_a->tab + i + 1);
	*(pile_a->tab + pile_a->size - 1) = tmp;
	i = 0;
	tmp = *(pile_b->tab + 0);
	*(pile_b->tab + 0) = *(pile_b->tab + 1);
	while (++i < pile_b->size - 1)
		*(pile_b->tab + i) = *(pile_b->tab + i + 1);
	*(pile_b->tab + pile_b->size - 1) = tmp;
	return (1);
}
