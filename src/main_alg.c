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

void	some_valid(t_ps *ps)
{
	while (ps->head_a->ind - ps->tail_a->ind == 1 ||
		ps->head_a->ind - ps->head_a->next->ind == 1)
	{
		if (ps->head_a->ind - ps->head_a->next->ind == 1)
		{
			s_exec(ps, "sa", 0);
		}
		else
		{
			ps->head_a->flag_b = -1;
			rr_exec(ps, "ra", 0);
		}
	}
}

void	new_part(t_ps *ps, t_num *a, int count, t_num *tmp)
{
	while (ps->count_a > 0)
	{
		tmp = a->next;
		if (ps->count_a <= 0)
		{
			ps->count_a = 0;
			break ;
		}
		if (a->data > ps->mid && a->flag_b != -1)
		{
			rr_exec(ps, "ra", 0);
			count = 0;
		}
		else if (a->flag_b != -1)
			p_exec(ps, "pb", 0);
		ps->count_a--;
		a = tmp;
	}
	max_search(ps, ps->head_b);
}

void	remaining_parts(t_ps *ps, t_num *a, t_num *tmp)
{
	while (a)
	{
		tmp = a->next;
		if (a->flag_b == ps->flag)
		{
			some_valid(ps);
			a = ps->head_a;
			tmp = a->next;
			if (a->flag_b == ps->flag)
			{
				if (ps->max < a->data)
					ps->max = a->data;
				p_exec(ps, "pb", 0);
			}
		}
		a = tmp;
	}
}

void	from_a_to_b(t_ps *ps, t_num *a, int k)
{
	t_num	*tmp;
	int		count;

	a = ps->head_a;
	tmp = NULL;
	if (ps->flag == 0)
	{
		count_search(ps, ps->head_a, 1);
		count = 1;
		min_search(ps, ps->head_a, 0);
		max_search(ps, ps->head_a);
		if (k == 0)
			ps->mid = ps->max / 2 + ps->min;
		else
			ps->mid = (ps->max - ps->min) / 2 + ps->min;
		new_part(ps, a, count, tmp);
		max_search(ps, ps->head_b);
	}
	else
		remaining_parts(ps, a, tmp);
}
