/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:29:57 by tmichel-          #+#    #+#             */
/*   Updated: 2023/01/04 13:48:45 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_pile
{
	int	size;
	int	*tab;
}		t_pile;

//PARSING.C
int		ft_error(char *err, int *tab);
int		ft_double(int *tab, int size);
void	ft_number(int ac, char **av, int *tab);
int		*parse_args(int ac, char **av, int *tab);
//MOVES.C
void	swap(t_pile *pile, char c);
void	ss(t_pile *pile_a, t_pile *pile_b);
void	push(t_pile *src, t_pile *dst, char c);
void	rotate(t_pile *pile, char c);
void	rr(t_pile *pile_a, t_pile *pile_b);
//MOVES_STRIKES_BACK.C
void	rev_rot(t_pile *pile, char c);
void	rrr(t_pile *pile_a, t_pile *pile_b);
// UTILS.C
int		ft_is_max(int *tab, int a, int size);
int		ft_is_min(int *tab, int a, int size);
int		ft_find_min_index(t_pile *pile);
int		ft_find_max_index(t_pile *pile);
void	ft_min_zero(t_pile *pile, char a);
// UTILS_ARE_BACK.C
void	ft_sort_int_tab(int *tab, int size);
int		ft_find_median(t_pile *pile, int size);
// UTILS_PRICE.C
int		ft_abs(int a);
int		ft_cost(t_pile *pile, int a);
int		ft_find_next(t_pile *pile_a, t_pile *pile_b, int a);
int		ft_totalcost(int price_a, int price_b);
int		ft_find_cheapest(t_pile *pile_a, t_pile *pile_b);
// LOOPS.C
void	do_rotate(t_pile *pile, char a, int i);
void	do_rev_rot(t_pile *pile, char a, int i);
void	loop_one(t_pile *pile_a, t_pile *pile_b, int i, int j);
void	loop_two(t_pile *pile_a, t_pile *pile_b, int i, int j);
void	loop_three(t_pile *pile_a, t_pile *pile_b, int i, int j);
//ALGORITHMS.C
int		sorted_pile(t_pile *pile);
void	alg_three(t_pile *pile, char c);
void	alg_five(t_pile *pile_a, char a, t_pile *pile_b, char b);
void	alg_bigstack(t_pile *pile_a, char a, t_pile *pile_b, char b);

#endif