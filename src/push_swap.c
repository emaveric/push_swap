/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:56:08 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/13 21:55:38 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b(t_ps *ps, t_num *a, t_num *b, int k)
{
	t_num	*tmp;

	ps->max = -2147483648;
	ps->min = 2147483647;
	min_search(ps, ps->head_b, -1);
	ps->mid = (ps->max - ps->min) / 2 + ps->min;
	if (k == 0)
		ps->flag++;
	b = ps->head_b;
	count_search(ps, ps->head_b, 2);
	//while (b)
	if (ps->count_b == 2)
	{
		sort_b_two_el(ps, a, b);
		return ;
	}
	if (ps->count_b == 3)
	{
		sort_b_three_el(ps, a, b);
		return ;
	}
	while(ps->count_b > 0)
	{
		tmp = b->next;
		if (b->data > ps->mid && b->data != ps->min)
		{
			b->flag_b = ps->flag;
			/*if (b->next)
				b = b->next;*/
			p_exec(ps, ps->head_a, ps->head_b, "pa");
			b = tmp;
			//printf("QQQdata %d ind %d flag_b %d\n", ps->head_a->data, ps->head_a->ind, ps->head_a->flag_b);
		}
		else if (b->data == ps->min)
		{
			b->flag_b = -1;
		/*	if (b->next)
				b = b->next;*/
			p_exec(ps, ps->head_a, ps->head_b, "pa");
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
			ps->min = 2147483647;
			min_search(ps, ps->head_b, -1);
			b = tmp;
		}
		else
			rr_exec(ps, ps->head_a, ps->head_b, "rb");
		b = tmp;
		ps->count_b--;
	}
	ps->max = ps->mid;
	if (ps->head_b)
		sort_b(ps, a, b, k);
}

void 	from_a_to_b(t_ps *ps, t_num *a, int k)
{
	int 	data;
	int 	ind;
	t_num	*tmp;

	a = ps->head_a;
	data = a->data;
	ind = 0;
	ps->max = -2147483648;
	ps->min = 2147483647;
	if (ps->flag == 0)
	{

		count_search(ps, ps->head_a, 1);
		min_search(ps, ps->head_a, 0);
		max_search(ps, ps->head_a);
		if (k == 0)
			ps->mid = ps->max / 2 + ps->min;
		else
			ps->mid = (ps->max - ps->min) / 2 + ps->min;
		//while (data != a->data || ind == 0)
		while (ps->count_a > 0)
		{
			tmp = a->next;
			if (a->data > ps->mid && a->flag_b != -1)
			{
				//a = a->next;
				rr_exec(ps, ps->head_a, ps->head_b, "ra");
				//a = tmp;
			}
			else if (a->flag_b != -1)
			{
				//a = a->next;
				p_exec(ps, ps->head_a, ps->head_b, "pb");
				//a = tmp;
			}
			ps->count_a--;
			a = tmp;
			//a = ps->head_a;
			ind = 1;
		}
		ps->max = ps->mid;
	}
	else
	{
		while (a)
		{
			tmp = a->next;
			if (a->flag_b == ps->flag)
			{
				if (ps->max < a->data)
					ps->max = a->data;
				p_exec(ps, ps->head_a, ps->head_b, "pb");
				//a = ps->head_a;
			}
			a = tmp;
		}
	}
}

void	more_than_five_alg(t_ps *ps, t_num *a, t_num *b, int k)
{
	from_a_to_b(ps, a, k);
	while (ps->tail_a->flag_b != -1 && k != 0)
	{
		rrr_exec(ps, ps->tail_a, ps->tail_b, "rra");
		ps->kol++;
	}
	sort_b(ps, a, b, 0);
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d flag_b %d\n", a->data, a->ind, a->flag_b);
		a = a->next;
	}
	printf ("!!!!\n\n");
	ps->max = -2147483648;
	ps->min = 2147483647;
	while (ps->flag > 0)
	{
		from_a_to_b(ps, a, k);
		if (ps->head_b)
			sort_b(ps, a, b, 1);
		ps->flag--;
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d flag_b %d\n", a->data, a->ind, a->flag_b);
		a = a->next;
	}
	printf("\n\n\n");
	while (ps->head_a->ind - ps->tail_a->ind == 1 ||
			ps->head_a->ind - ps->head_a->next->ind == 1)
	{
		if (ps->head_a->ind - ps->head_a->next->ind == 1)
			s_exec(ps, ps->head_a, ps->head_b, "sa");
		else
		{
			ps->head_a->flag_b = -1;
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
		}
	}
	/*a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d flag_b %d\n", a->data, a->ind, a->flag_b);
		a = a->next;
	}
	printf("\n\n\n");*/
	if (ps->kol > 0)
	{
		ps->kol = 0;
		more_than_five_alg(ps, a, b, ++k);
	}
}

int 	start_alg(int ac, t_ps *ps, t_num *a, t_num *b)
{
	if (ac > 6)
		more_than_five_alg(ps, a, b, 0);
	if (ac == 6 || ps->kol == 5)
		for_five_el_alg(ps, a, b);
	if (ac == 5 || ps->kol == 4)
		for_four_el_alg(ps, a, b, 0);
	if (ac == 4 || ps->kol == 3)
		for_three_el_alg(ps, a, b, 0);
	if (ac == 3 || ps->kol == 2)
		for_two_el_alg(ps, a, b);
	return (0);
}

int 	main(int ac, char **av)
{
	t_num	*a;
	t_num	*b;
	t_ps	*ps;

	if (ac > 1)
	{
		if (!(ps = init_ps()))
			return (-1);
	//	if (!(a = init_num()))
		//	return (-1);
		//if (!(b = init_num()))
			//return (-1);
		if (check_num(ps, ps->head_a, av) == -1)
			return (0);
		check_ind(ps, ps->head_a);
		start_alg(ac, ps, ps->head_a, ps->head_b);
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
	}
	return (0);
}