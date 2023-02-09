/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 11:41:46 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/04 19:22:34 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_print_checker(t_pile *pile_a, t_pile *pile_b, int i)
{
	free(pile_a->tab);
	free(pile_b->tab);
	if (i == 1)
		ft_printf("OK\n");
	else if (i == 2)
		ft_putstr_fd("Error\n", 2);
	else
		ft_printf("%s", "KO\n");
	exit(0);
}

void	sorted_pile_checker(t_pile *pile_a, t_pile *pile_b)
{
	int	i;

	i = -1;
	while (++i < pile_a->size - 1)
	{
		if (*(pile_a->tab + i) > *(pile_a->tab + i + 1))
			ft_print_checker(pile_a, pile_b, 0);
	}
	if (i == pile_a->size - 1 && pile_b->size == 0)
		ft_print_checker(pile_a, pile_b, 1);
	ft_print_checker(pile_a, pile_b, 0);
}

void	checker(t_pile *pile_a, t_pile *pile_b)
{
	char	*move;
	int		i;

	while (1)
	{
		i = 0;
		move = get_next_line(0);
		if (!move)
			break ;
		i = check_move(pile_a, pile_b, i, move);
		i += check_move_others(pile_a, pile_b, i, move);
		if (!i)
		{
			free(move);
			ft_print_checker(pile_a, pile_b, 2);
		}	
		free(move);
	}
	sorted_pile_checker(pile_a, pile_b);
}

int	main(int ac, char **av)
{
	t_pile	pile_a;
	t_pile	pile_b;

	if (ac < 2)
		return (0);
	pile_a.tab = malloc(sizeof(int) * (ac - 1));
	if (!pile_a.tab)
		return (0);
	pile_a.tab = parse_args(ac, av, pile_a.tab);
	pile_a.size = ac - 1;
	pile_b.tab = malloc(sizeof(int) * (ac - 1));
	if (!pile_b.tab)
		return (free(pile_a.tab), 0);
	pile_b.size = 0;
	checker(&pile_a, &pile_b);
	free(pile_a.tab);
	free(pile_b.tab);
	return (0);
}
