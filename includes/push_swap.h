/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:09:37 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:24:59 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include "../ft_printf/libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"

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
	int					flag_v;
	int 				max;
	int					mid;
	int 				min;
	int 				min_ind;
	int 				kol;
	int 				count_a;
	int 				count_b;
}						t_ps;

void 	instr_execution(t_ps *ps, char *line, int k);
int 	check_sort(t_ps *ps, t_num *a);
int 	check_rep_value(t_num *a, int data, int ind);
int 	check_start_sort(t_ps *ps, t_num *a);
int 	check_valid_instr(char *line);
int		check_ind(t_ps *ps, t_num *a);
int		check_num(t_ps *ps, t_num *a, char **av);
int		init_new(t_num **a, t_ps **ps);
t_num	*init_num(void);
t_ps	*init_ps(void);
void	free_t_num(t_num *tmp);
void	output_stacks(t_ps **ps);
void 	s_exec(t_ps *ps, char *line, int k);
void	p_exec(t_ps *ps, char *line, int k);
void	rr_exec(t_ps *ps, char *line, int k);
void	rrr_exec(t_ps *ps, char *line, int k);
void	min_search(t_ps *ps, t_num *n, int k);
void 	from_a_to_b(t_ps *ps, t_num *a, int k);
void	sort_b(t_ps *ps, t_num *a, t_num *b, int k);
void	some_valid(t_ps *ps);
void	for_two_el_alg(t_ps *ps, t_num *a);
void	for_three_el_alg(t_ps *ps, t_num *a, int k);
void	for_four_el_alg(t_ps *ps, t_num *a, int k);
void	for_five_el_alg(t_ps *ps, t_num *a);
void	max_search(t_ps *ps, t_num *n);
void	count_search(t_ps *ps, t_num *n, int k);
void 	remaining_parts(t_ps *ps, t_num *a, t_num *tmp);
void	sort_b_main(t_ps *ps, t_num *b, int max_data);
void	some_valid(t_ps *ps);
void	free_t_ps(t_ps **ps, t_num **a);
void	free_t_num(t_num *tmp);

#endif
