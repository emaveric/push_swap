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

void	sort_b_three_el_p2(t_ps *ps, t_num *a, t_num *b)
{
	if (b->next->data == ps->min)
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
}

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
	else
		sort_b_three_el_p2(ps, a, b);
	sort_b_two_el(ps, ps->head_a, ps->head_b, 1);
}

void	sort_b_main(t_ps *ps, t_num *a, t_num *b, int max_data)
{
	/*//tmp = b->next;
	if (b->data > ps->mid && b->ind != ps->min_ind)
	{
		b->flag_b = ps->flag;
		max_data = b->data;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		ps->sum++;
		//printf("QQQdata %d ind %d flag_b %d\n", ps->head_a->data, ps->head_a->ind, ps->head_a->flag_b);
	}
	//else if (b->data == ps->min)
	else if (b->ind == ps->min_ind)
	{
		b->flag_b = -1;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		if (ps->head_b && ps->head_b->data <= ps->mid && ps->head_b->ind != ps->min_ind + 1) // НА 1 БОЛЬШЕ??????????
			rr_exec(ps, ps->head_a, ps->head_b, "rr");
		else
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
		//ps->min = 2147483647;
		//min_search(ps, ps->head_b, -1);
		//ps->min_ind++;
		some_valid(ps);
		ps->min_ind = ps->tail_a->ind + 1;
		ps->sum += 2;
		if (ps->head_b && ps->min > max_data)
		{
		ps->count_b--;
		ps->head_b->flag_b = ps->flag;
		p_exec(ps, ps->head_a, ps->head_b, "pa");
		ps->sum++;
		}
	}
	else
	{
		rr_exec(ps, ps->head_a, ps->head_b, "rb");
		ps->sum++;
	}
	b = ps->head_b;
	ps->count_b--;
	return;*/
	while (ps->count_b > 0)
	{
		//tmp = b->next;
		if (b->data > ps->mid && b->ind != ps->min_ind)
		{
			b->flag_b = ps->flag;
			max_data = b->data;
			p_exec(ps, ps->head_a, ps->head_b, "pa");
			ps->sum++;
			//printf("QQQdata %d ind %d flag_b %d\n", ps->head_a->data, ps->head_a->ind, ps->head_a->flag_b);
		}
			//else if (b->data == ps->min)
		else if (b->ind == ps->min_ind)
		{
			b->flag_b = -1;
			p_exec(ps, ps->head_a, ps->head_b, "pa");
			if (ps->head_b && ps->head_b->data <= ps->mid && ps->head_b->ind != ps->min_ind + 1) // НА 1 БОЛЬШЕ??????????
				rr_exec(ps, ps->head_a, ps->head_b, "rr");
			else
				rr_exec(ps, ps->head_a, ps->head_b, "ra");
			//ps->min = 2147483647;
			//min_search(ps, ps->head_b, -1);
			//ps->min_ind++;
			some_valid(ps);
			ps->min_ind = ps->tail_a->ind + 1;
			ps->sum += 2;
			/*if (ps->head_b && ps->min > max_data)
			{
				ps->count_b--;
				ps->head_b->flag_b = ps->flag;
				p_exec(ps, ps->head_a, ps->head_b, "pa");
				ps->sum++;
			}*/
		}
		else
		{
			rr_exec(ps, ps->head_a, ps->head_b, "rb");
			ps->sum++;
		}
		b = ps->head_b;
		ps->count_b--;
	}
}

void	sort_b(t_ps *ps, t_num *a, t_num *b, int k)
{
	t_num	*tmp;
	int 	max_data;

	//ps->min = 2147483647;
	max_data = 0;
	min_search(ps, ps->head_b, -1);
	ps->mid = (ps->max - ps->min) / 2 + ps->min;
	count_search(ps, ps->head_b, 2);
	if (k == 0) //&& ps->count_b != 1)
		ps->flag++;
	b = ps->head_b;
	if (ps->count_b == 2)
	{
		sort_b_two_el(ps, a, b, 0);
		return ;
	}
	if (ps->count_b == 3)
	{
		sort_b_three_el(ps, a, b);
		return ;
	}
	sort_b_main(ps, a, b, max_data);
	/*while (ps->count_b > 0)
	{
		//tmp = b->next;
		if (b->data > ps->mid && b->ind != ps->min_ind)
		{
			b->flag_b = ps->flag;
			max_data = b->data;
			p_exec(ps, ps->head_a, ps->head_b, "pa");
			ps->sum++;
			//printf("QQQdata %d ind %d flag_b %d\n", ps->head_a->data, ps->head_a->ind, ps->head_a->flag_b);
		}
			//else if (b->data == ps->min)
		else if (b->ind == ps->min_ind)
		{
			b->flag_b = -1;
			p_exec(ps, ps->head_a, ps->head_b, "pa");
			if (ps->head_b && ps->head_b->data <= ps->mid && ps->head_b->ind != ps->min_ind + 1) // НА 1 БОЛЬШЕ??????????
				rr_exec(ps, ps->head_a, ps->head_b, "rr");
			else
				rr_exec(ps, ps->head_a, ps->head_b, "ra");
			//ps->min = 2147483647;
			//min_search(ps, ps->head_b, -1);
			//ps->min_ind++;
			some_valid(ps);
			ps->min_ind = ps->tail_a->ind + 1;
			ps->sum += 2;
			*//*if (ps->head_b && ps->min > max_data)
			{
				ps->count_b--;
				ps->head_b->flag_b = ps->flag;
				p_exec(ps, ps->head_a, ps->head_b, "pa");
				ps->sum++;
			}*//*
		}
		else
		{
			rr_exec(ps, ps->head_a, ps->head_b, "rb");
			ps->sum++;
		}
		b = ps->head_b;
		ps->count_b--;
	}*/
	// ps->tail_b = null??
	if (ps->head_b == NULL && k != 0)
		ps->flag++;
	ps->max = ps->mid;
	if (ps->head_b)
		sort_b(ps, a, b, 0);
	else
		ps->tail_b = NULL; // нужно ли? (пока не влияет ни на что)
}