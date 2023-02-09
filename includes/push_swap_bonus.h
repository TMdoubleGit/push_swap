/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmichel- <tmichel-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 10:29:57 by tmichel-          #+#    #+#             */
/*   Updated: 2022/12/30 18:27:59 by tmichel-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
int		sorted_pile(t_pile *pile);
int		ft_error(char *err, int *tab);
int		ft_double(int *tab, int size);
void	ft_number(int ac, char **av, int *tab);
int		*parse_args(int ac, char **av, int *tab);
//MOVES.C
int		swap(t_pile *pile, char c);
int		ss(t_pile *pile_a, t_pile *pile_b);
int		push(t_pile *src, t_pile *dst, char c);
int		rotate(t_pile *pile, char c);
int		rr(t_pile *pile_a, t_pile *pile_b);
//MOVES_STRIKES_BACK.C
int		rev_rot(t_pile *pile, char c);
int		rrr(t_pile *pile_a, t_pile *pile_b);
int		check_move(t_pile *pile_a, t_pile *pile_b, int i, char *move);
int		check_move_others(t_pile *pile_a, t_pile *pile_b, int i, char *move);
// CHECKER.C
void	ft_print_checker(t_pile *pile_a, t_pile *pile_b, int i);
void	sorted_pile_checker(t_pile *pile_a, t_pile *pile_b);
void	checker(t_pile *pile_a, t_pile *pile_b);

#endif