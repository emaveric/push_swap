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

void	new_part(t_ps *ps, t_num *a, int count, t_num *tmp)
{
	while (ps->count_a > 0)
	{
		tmp = a->next;
		/*	if (count == 1) // нужно ли вообще? нужно ли условие  k != 0
			{
				ps->min_ind = ps->tail_a->ind;//
				some_valid(ps); // эти // строки не уверен, работает со 100 и снижает кол-во шагов (сильно)
				a = ps->head_a; //
				ps->count_a = ps->count_a - (ps->tail_a->ind - ps->min_ind);//
				tmp = a->next; //
			}*/
		if (ps->count_a <= 0)
		{
			ps->count_a = 0;
			break ;
		}
		if (a->data > ps->mid && a->flag_b != -1)
		{
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
			ps->sum++;
			count = 0;
		}
		else if (a->flag_b != -1)
		{
			p_exec(ps, ps->head_a, ps->head_b, "pb");
			ps->sum++;
		}
		ps->count_a--;
		a = tmp;
	}
	max_search(ps, ps->head_b);
}

void 	remaining_parts(t_ps *ps, t_num *a, t_num *tmp)
{
	while (a)
	{
		tmp = a->next;
		if (a->flag_b == ps->flag)
		{
			some_valid(ps); // эти 3 строки не уверен, работает со 100 и снижает кол-во шагов (сильно)
			a = ps->head_a; //
			tmp = a->next; //
			if (a->flag_b == ps->flag)
			{
				if (ps->max < a->data)
					ps->max = a->data;
				p_exec(ps, ps->head_a, ps->head_b, "pb");
				ps->sum++;
			}
		}
		a = tmp;
	}
}

void 	from_a_to_b(t_ps *ps, t_num *a, int k)
{
	t_num	*tmp;
	int 	count;

	a = ps->head_a;
	if (ps->flag == 0)
	{
		/*ps->max = -2147483648;
		ps->min = 2147483647;*/
		count_search(ps, ps->head_a, 1);
		count = 1;
		min_search(ps, ps->head_a, 0);
		max_search(ps, ps->head_a);
		if (k == 0)
			ps->mid = ps->max / 2 + ps->min;
		else
			ps->mid = (ps->max - ps->min) / 2 + ps->min;
		new_part(ps, a, count, tmp);
	/*	while (ps->count_a > 0)
		{
			tmp = a->next;
		*//*	if (count == 1) // нужно ли вообще? нужно ли условие  k != 0
			{
				ps->min_ind = ps->tail_a->ind;//
				some_valid(ps); // эти // строки не уверен, работает со 100 и снижает кол-во шагов (сильно)
				a = ps->head_a; //
				ps->count_a = ps->count_a - (ps->tail_a->ind - ps->min_ind);//
				tmp = a->next; //
			}*//*
			if (ps->count_a <= 0)
			{
				ps->count_a = 0;
				break ;
			}
			if (a->data > ps->mid && a->flag_b != -1)
			{
				rr_exec(ps, ps->head_a, ps->head_b, "ra");
				ps->sum++;
				count = 0;
			}
			else if (a->flag_b != -1)
			{
				p_exec(ps, ps->head_a, ps->head_b, "pb");
				ps->sum++;
			}
			ps->count_a--;
			a = tmp;
		}*/
		max_search(ps, ps->head_b);
	}
	else
		remaining_parts(ps, a, tmp);
	/*{
		while (a)
		{
			tmp = a->next;
			if (a->flag_b == ps->flag)
			{
				some_valid(ps); // эти 3 строки не уверен, работает со 100 и снижает кол-во шагов (сильно)
				a = ps->head_a; //
				tmp = a->next; //
				if (a->flag_b == ps->flag)
				{
					if (ps->max < a->data)
						ps->max = a->data;
					p_exec(ps, ps->head_a, ps->head_b, "pb");
					ps->sum++;
				}
			}
			a = tmp;
		}
	}*/
}
