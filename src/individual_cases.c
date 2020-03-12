/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   individual_cases.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 19:48:02 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/12 20:48:32 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	for_five_el_alg(t_ps *ps, t_num *a, t_num *b)
{
	a = ps->head_a;
	min_search(ps, ps->head_a, 0);
	if (ps->min == ps->head_a->data)
	{
		ps->min = a->next->data;
		rr_exec(ps, a, b, "ra");
		for_four_el_alg(ps, a, b, 4);
	}
	else
	{
		while (ps->head_a->data != ps->min)
			rr_exec(ps, a, b, "ra");
		ps->min = ps->head_a->next->data;
		p_exec(ps, a, b, "pb");
		for_four_el_alg(ps, a, b, 0);
		p_exec(ps, a, b, "pa");
	}
}

void	for_four_el_alg(t_ps *ps, t_num *a, t_num *b, int k)
{
	a = ps->head_a;
	min_search(ps, ps->head_a, 0);
	if (ps->min == ps->head_a->data)
	{
		ps->min = a->next->data;
		rr_exec(ps, a, b, "ra");
		for_three_el_alg(ps, a, b, 3);
	}
	else
	{
		while (ps->head_a->data != ps->min)
			rr_exec(ps, a, b, "ra");
		ps->min = ps->head_a->next->data;
		p_exec(ps, a, b, "pb");
		for_three_el_alg(ps, a, b, 0);
		p_exec(ps, a, b, "pa");
	}
}

void	for_three_el_alg(t_ps *ps, t_num *a, t_num *b, int k)
{
	a = ps->head_a;
	min_search(ps, ps->head_a, k);
	if (ps->min == ps->head_a->data)
	{
		rr_exec(ps, a, b, "ra");
		for_two_el_alg(ps ,a, b);
	}
	else
	{
		if (a->next->data == ps->min)
		{
			if (ps->tail_a->data < ps->head_a->data)
				rr_exec(ps, a, b, "ra");
			else
				s_exec(ps, a, b, "sa");
		}
		else if (ps->tail_a->data == ps->min)
		{
			if (ps->head_a->data > a->next->data)
				s_exec(ps, a, b, "sa");
			rr_exec(ps, a, b, "ra");
			rr_exec(ps, a, b, "ra");
		}
	}
}

void	for_two_el_alg(t_ps *ps, t_num *a, t_num *b)
{
	a = ps->head_a;
	if (a->data > a->next->data)
		s_exec(ps, a, b, "sa");
}