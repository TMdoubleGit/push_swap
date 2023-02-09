/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:29:31 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/02 12:10:06 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile *pile, char c)
{
	int	i;
	int	tmp;

	i = 0;
	if (!pile->size)
		return ;
	tmp = *(pile->tab + 0);
	*(pile->tab + 0) = *(pile->tab + 1);
	*(pile->tab + 1) = tmp;
	ft_printf("s%c\n", c);
}

void	ss(t_pile *pile_a, t_pile *pile_b)
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
	ft_printf("ss\n");
}

void	push(t_pile *src, t_pile *dst, char c)
{
	int	i;
	int	j;
	int	tmp;

	if (!src->size)
		return ;
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
	ft_printf("p%c\n", c);
}

void	rotate(t_pile *pile, char c)
{
	int	i;
	int	tmp;

	if (!pile->size)
		return ;
	i = 0;
	tmp = *(pile->tab + 0);
	*(pile->tab + 0) = *(pile->tab + 1);
	while (++i < pile->size - 1)
		*(pile->tab + i) = *(pile->tab + i + 1);
	*(pile->tab + pile->size - 1) = tmp;
	ft_printf("r%c\n", c);
}

void	rr(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	tmp;

	if (!pile_a->size || !pile_b->size)
		return ;
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
	ft_printf("rr\n");
}
