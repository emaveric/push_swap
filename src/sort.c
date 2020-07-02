/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:56:08 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 21:26:42 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b_two_el(t_ps *ps, t_num *b, int k)
{
	if (ps->head_b->data > b->next->data)
	{
		if (k == 0)
			s_exec(ps, "sb", 0);
		else
			rr_exec(ps, "rr", 0);
	}
	ps->head_b->flag_b = -1;
	p_exec(ps, "pa", 0);
	rr_exec(ps, "ra", 0);
	ps->head_b->flag_b = -1;
	p_exec(ps, "pa", 0);
	rr_exec(ps, "ra", 0);
	ps->tail_b = NULL;
	ps->count_b = 0;
}

void	sort_b_three_el_p2(t_ps *ps, t_num *b)
{
	if (b->next->data == ps->min)
	{
		s_exec(ps, "sb", 0);
		ps->head_b->flag_b = -1;
		p_exec(ps, "pa", 0);
		if (ps->head_b->data < ps->head_b->next->data)
			rr_exec(ps, "ra", 0);
	}
	else if (ps->tail_b->data == ps->min)
	{
		rrr_exec(ps, "rrb", 0);
		ps->head_b->flag_b = -1;
		p_exec(ps, "pa", 0);
		if (ps->head_b->data < ps->head_b->next->data)
			rr_exec(ps, "ra", 0);
	}
}

void	sort_b_three_el(t_ps *ps, t_num *b)
{
	if (ps->head_b->data == ps->min)
	{
		ps->head_b->flag_b = -1;
		p_exec(ps, "pa", 0);
		if (ps->head_b->data < ps->head_b->next->data)
			rr_exec(ps, "ra", 0);
	}
	else
		sort_b_three_el_p2(ps, b);
	sort_b_two_el(ps, ps->head_b, 1);
}

void	sort_b_main(t_ps *ps, t_num *b, int max_data)
{
	while (ps->count_b > 0)
	{
		if (b->data > ps->mid && b->ind != ps->min_ind)
		{
			b->flag_b = ps->flag;
			max_data = b->data;
			p_exec(ps, "pa", 0);
		}
		else if (b->ind == ps->min_ind)
		{
			b->flag_b = -1;
			p_exec(ps, "pa", 0);
			if (ps->head_b && ps->head_b->data <= ps->mid &&
			ps->head_b->ind != ps->min_ind + 1)
				rr_exec(ps, "rr", 0);
			else
				rr_exec(ps, "ra", 0);
			some_valid(ps);
			ps->min_ind = ps->tail_a->ind + 1;
		}
		else
			rr_exec(ps, "rb", 0);
		b = ps->head_b;
		ps->count_b--;
	}
}

void	sort_b(t_ps *ps, t_num *a, t_num *b, int k)
{
	int		max_data;

	max_data = 0;
	min_search(ps, ps->head_b, -1);
	ps->mid = (ps->max - ps->min) / 2 + ps->min;
	count_search(ps, ps->head_b, 2);
	if (k == 0)
		ps->flag++;
	b = ps->head_b;
	if (ps->count_b == 2)
	{
		sort_b_two_el(ps, b, 0);
		return ;
	}
	if (ps->count_b == 3)
	{
		sort_b_three_el(ps, b);
		return ;
	}
	sort_b_main(ps, b, max_data);
	if (ps->head_b == NULL && k != 0)
		ps->flag++;
	ps->max = ps->mid;
	if (ps->head_b)
		sort_b(ps, a, b, 0);
}
