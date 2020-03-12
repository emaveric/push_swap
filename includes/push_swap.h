/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:09:37 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/12 20:26:32 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct			s_num
{
	struct s_num		*next;
	struct s_num		*prev;
	int 				data;
	int 				ind;
	int 				flag_b;

}						t_num;

typedef struct			s_ps
{
	struct s_num		*head_a;
	struct s_num		*tail_a;
	struct s_num		*head_b;
	struct s_num		*tail_b;
	int 				flag;
	int 				max;
	int					mid;
	int 				min;
	int 				kol;
}						t_ps;

void	instr_execution(t_ps *ps, t_num *a, t_num *b, char *line);
int 	check_sort(t_ps *ps, t_num *a);
int 	check_valid_instr(char *line);
void	check_ind(t_ps *ps, t_num *a);
int		check_num(t_ps *ps, t_num *a, char **av);
t_num	*init_num(void);
t_ps	*init_ps(void);
void	free_t_num(t_num *tmp);
void 	s_exec(t_ps *ps, t_num *a, t_num *b, char *line);
void	p_exec(t_ps *ps, t_num *a, t_num *b, char *line);
void	rr_exec(t_ps *ps, t_num *a, t_num *b, char *line);
void	rrr_exec(t_ps *ps, t_num *a, t_num *b, char *line);
void	min_search(t_ps *ps, t_num *n, int k);
void	for_two_el_alg(t_ps *ps, t_num *a, t_num *b);
void	for_three_el_alg(t_ps *ps, t_num *a, t_num *b, int k);
void	for_four_el_alg(t_ps *ps, t_num *a, t_num *b, int k);
void	for_five_el_alg(t_ps *ps, t_num *a, t_num *b);

#endif
