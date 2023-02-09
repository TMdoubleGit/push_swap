/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 15:11:09 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/02 14:47:13 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_pile	pile_a;
	t_pile	pile_b;

	if (ac < 2)
		return (0);
	pile_a.tab = malloc(sizeof(int) * (ac - 1));
	if (!pile_a.tab)
		return (0);
	pile_a.size = ac - 1;
	pile_a.tab = parse_args(ac, av, pile_a.tab);
	pile_b.tab = malloc(sizeof(int) * (ac - 1));
	if (!pile_b.tab)
		return (free(pile_a.tab), 0);
	pile_b.size = 0;
	if (sorted_pile(&pile_a) == 1)
		return (free(pile_a.tab), free(pile_b.tab), 0);
	if (pile_a.size <= 5)
		alg_five(&pile_a, 'a', &pile_b, 'b');
	else
		alg_bigstack(&pile_a, 'a', &pile_b, 'b');
	free(pile_a.tab);
	return (free(pile_b.tab), 0);
}
