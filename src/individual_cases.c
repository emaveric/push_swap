/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   individual_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:48:02 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 18:54:10 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	for_five_el_alg(t_ps *ps, t_num *a, t_num *b)
{
	a = ps->head_a;
	min_search(ps, ps->head_a, 0);
	while (ps->head_a->data != ps->min)
	{
		rr_exec(ps, ps->head_a, b, "ra");
		ps->sum++;
	}
	ps->min = ps->head_a->next->data;
	p_exec(ps, ps->head_a, ps->head_b, "pb");
	for_four_el_alg(ps, a, 0);
	p_exec(ps, ps->head_a, ps->head_b, "pa");
	ps->sum += 2;
}

void	for_four_el_alg(t_ps *ps, t_num *a, int k)
{
	a = ps->head_a;
	min_search(ps, ps->head_a, k);
	while (ps->head_a->data != ps->min)
	{
		rr_exec(ps, ps->head_a, ps->head_b, "ra");
		ps->sum++;
	}
	ps->min = ps->head_a->next->data;
	p_exec(ps, ps->head_a, ps->head_b, "pb");
	for_three_el_alg(ps, a, 3);
	p_exec(ps, ps->head_a, ps->head_b, "pa");
	ps->sum += 2;
}

void	for_three_el_alg(t_ps *ps, t_num *a, int k)
{
	a = ps->head_a;
	min_search(ps, ps->head_a, k);
	if (ps->min == ps->head_a->data)
	{
		rr_exec(ps, ps->head_a, ps->head_b, "ra");
		for_two_el_alg(ps, ps->head_a);
		rrr_exec(ps, ps->tail_a, ps->tail_b, "rra");
		ps->sum += 2;
	}
	else
	{
		if (a->next->data == ps->min)
		{
			if (ps->tail_a->data < ps->head_a->data)
				rr_exec(ps, ps->head_a, ps->head_b, "ra");
			else
				s_exec(ps, ps->head_a, ps->head_b, "sa");
			ps->sum++;
		}
		else if (ps->tail_a->data == ps->min)
		{
			if (ps->head_a->data > a->next->data)
			{
				s_exec(ps, ps->head_a, ps->head_b, "sa");
				ps->sum++;
			}
			rrr_exec(ps, ps->tail_a, ps->tail_b, "rra");
		//	rr_exec(ps, ps->head_a, ps->head_b, "ra");
			ps->sum += 1;
		} // удалить ps->sum и в норме
	}
}

void	for_two_el_alg(t_ps *ps, t_num *a)
{
	a = ps->head_a;
	if (a->data > a->next->data)
	{
		s_exec(ps, ps->head_a, ps->head_b, "sa");
		ps->sum++;
	}
}