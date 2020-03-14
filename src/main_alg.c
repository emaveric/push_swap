/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:01:59 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/14 17:26:21 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b_three_el(t_ps *ps, t_num *a, t_num *b)
{
	if (ps->head_b->data == ps->min)
	{
		ps->head_b->flag_b = -1;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		rr_exec(ps, ps->head_a, ps->head_b, "ra");
	}
	else if (b->next->data == ps->min)
	{
		s_exec(ps, ps->head_a, ps->head_b, "sb");
		ps->head_b->flag_b = -1;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		rr_exec(ps, ps->head_a, ps->head_b, "ra");
	}
	else if (ps->tail_b->data == ps->min)
	{
		rrr_exec(ps, ps->tail_a, ps->tail_b, "rrb");
		ps->head_b->flag_b = -1;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		rr_exec(ps, ps->head_a, ps->head_b, "ra");
	}
	sort_b_two_el(ps, ps->head_a, ps->head_b);
	ps->count_b = 0;
}

void	sort_b_two_el(t_ps *ps, t_num *a, t_num *b)
{
	if (ps->head_b->data > b->next->data)
		s_exec(ps, ps->head_a, ps->head_b, "sb");
	ps->head_b->flag_b = -1;
	p_exec(ps, ps->head_a, ps->head_b, "pa");
	rr_exec(ps, ps->head_a, ps->head_b, "ra");
	ps->head_b->flag_b = -1;
	p_exec(ps, ps->head_a, ps->head_b, "pa");
	rr_exec(ps, ps->head_a, ps->head_b, "ra");
	ps->count_b = 0;
}