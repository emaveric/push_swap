/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_alg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 21:01:59 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 20:17:10 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b_three_el(t_ps *ps, t_num *a, t_num *b)
{
	if (ps->head_b->data == ps->min)
	{
		ps->head_b->flag_b = -1;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		if (ps->head_b->data < ps->head_b->next->data)
		{
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
			ps->sum++;
		}
		// rr_exec(ps, ps->head_a, ps->head_b, "ra");
		ps->sum++;
	}
	else if (b->next->data == ps->min)
	{
		s_exec(ps, ps->head_a, ps->head_b, "sb");
		ps->head_b->flag_b = -1;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		if (ps->head_b->data < ps->head_b->next->data)
		{
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
			ps->sum++;
		}
		//rr_exec(ps, ps->head_a, ps->head_b, "ra");
		ps->sum += 2;
	}
	else if (ps->tail_b->data == ps->min)
	{
		rrr_exec(ps, ps->tail_a, ps->tail_b, "rrb");
		ps->head_b->flag_b = -1;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		if (ps->head_b->data < ps->head_b->next->data)
		{
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
			ps->sum++;
		}
		//rr_exec(ps, ps->head_a, ps->head_b, "ra");
		ps->sum += 2;
	}
	sort_b_two_el(ps, ps->head_a, ps->head_b, 1);
}

void	sort_b_two_el(t_ps *ps, t_num *a, t_num *b, int k)
{
	if (ps->head_b->data > b->next->data)
	{
		if (k == 0)
		s_exec(ps, ps->head_a, ps->head_b, "sb");
		else
			rr_exec(ps, ps->head_a, ps->head_b, "rr");
		ps->sum++;
	}
	ps->head_b->flag_b = -1;
	p_exec(ps, ps->head_a, ps->head_b, "pa");
	rr_exec(ps, ps->head_a, ps->head_b, "ra");
	ps->head_b->flag_b = -1;
	p_exec(ps, ps->head_a, ps->head_b, "pa");
	rr_exec(ps, ps->head_a, ps->head_b, "ra");
	ps->sum += 4;
    ps->tail_b = NULL;
	ps->count_b = 0;
}