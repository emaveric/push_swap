/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:56:08 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/12 21:15:26 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b(t_ps *ps, t_num *a, t_num *b)
{
	ps->mid = (ps->max - ps->min) / 2 + ps->min;
	ps->flag++;
	b = ps->head_b;
	while (b)
	{
		if (b->data > ps->mid)
		{
			b->flag_b = ps->flag;
			p_exec(ps, a, b, "pa");
			printf("QQQdata %d ind %d flag_b %d\n", ps->head_a->data, ps->head_a->ind, ps->head_a->flag_b);
		}
		if (b->data == ps->min)
		{
			b->flag_b = -1;
			p_exec(ps, a, b, "pa");
			rr_exec(ps, a, b, "ra");
			min_search(ps, ps->head_b, 0);
		}
		b = b->next;
	}
	ps->max = ps->mid;
	if (ps->head_b->ind != -1)
		sort_b(ps, a, b);
}

void 	from_a_to_b(t_ps *ps, t_num *a, t_num *b)
{
	a = ps->head_a;
	if (ps->flag == 0)
	{
		ps->mid = ps->max / 2 + ps->min;
		while (a)
		{
			if (a->data > ps->mid)
				rr_exec(ps, a, b, "ra");
			else
				p_exec(ps, a, b, "pb");
			a = a->next;
		}
		ps->max = ps->mid;
	}
	else
	{
		while (a)
		{
			if (a->flag_b == ps->flag)
			{
				if (ps->max < a->data)
					ps->max = a->data;
				p_exec(ps, a, b, "pb");
			}
			a = a->next;
		}
	}
}

void	more_than_five_alg(t_ps *ps, t_num *a, t_num *b, int k)
{
	from_a_to_b(ps, a, b);
	while (ps->tail_a->flag_b != -1 && k != 0)
	{
		rrr_exec(ps, a, b, "rra");
		ps->kol++;
	}
	sort_b(ps, a, b);
	while (ps->flag > 0)
	{
		from_a_to_b(ps, a, b);
		if (ps->head_b->ind != -1)
			sort_b(ps, a, b);
		ps->flag--;
	}
	while (ps->head_a->ind - ps->tail_a->ind == 1)
	{
		ps->head_a->flag_b = -1;
		rr_exec(ps, a, b, "ra");
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d flag_b %d\n", a->data, a->ind, a->flag_b);
		a = a->next;
	}
	printf("\n\n\n");
	if (ps->kol > 5)
	{
		ps->kol = 0;
		more_than_five_alg(ps, a, b, k++);
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
		if (!(a = init_num()))
			return (-1);
		if (!(b = init_num()))
			return (-1);
		if (check_num(ps, a, av) == -1)
			return (0);
		check_ind(ps, a);
		start_alg(ac, ps, a, b);
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
	}
	return (0);
}