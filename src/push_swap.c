/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:56:08 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 21:26:42 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	some_valid(t_ps *ps)
{
	while (ps->head_a->ind - ps->tail_a->ind == 1 ||
		   ps->head_a->ind - ps->head_a->next->ind == 1)
	{ /*||
			(ps->head_b == NULL && ps->tail_b == NULL && ps->head_a->next->next->ind - ps->tail_a->ind == 1))
	{
		if (ps->head_b == NULL && ps->tail_b == NULL && ps->head_a->next->next->ind - ps->tail_a->ind == 1)
		{
			p_exec(ps, ps->head_a, ps->head_b, "pb");
			s_exec(ps, ps->head_a, ps->head_b, "sa");
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
			p_exec(ps, ps->head_a, ps->head_b, "pa");
			ps->sum += 4;
		}
		else */if (ps->head_a->ind - ps->head_a->next->ind == 1)
		{
			s_exec(ps, ps->head_a, ps->head_b, "sa");
			ps->sum++;
		}
		else
		{
			ps->head_a->flag_b = -1;
			rr_exec(ps, ps->head_a, ps->head_b, "ra");
			//if (ps->head_a->flag_b != ps->flag) // тест на ошибку при 500 с лишними флагами
			//    ps->flag--;
			ps->sum++;
		}
	}
}


/*void 	from_a_to_b(t_ps *ps, t_num *a, int k)
{
	t_num	*tmp;
	int 	count;

	a = ps->head_a;
	if (ps->flag == 0)
	{
		*//*ps->max = -2147483648;
		ps->min = 2147483647;*//*
		count_search(ps, ps->head_a, 1);
		count = 1;
		min_search(ps, ps->head_a, 0);
		max_search(ps, ps->head_a);
		if (k == 0)
			ps->mid = ps->max / 2 + ps->min;
		else
			ps->mid = (ps->max - ps->min) / 2 + ps->min;
		while (ps->count_a > 0)
		{
			tmp = a->next;
			if (count == 1) // нужно ли вообще? нужно ли условие  k != 0
			{
				ps->min_ind = ps->tail_a->ind;//
				some_valid(ps); // эти // строки не уверен, работает со 100 и снижает кол-во шагов (сильно)
				a = ps->head_a; //
				ps->count_a = ps->count_a - (ps->tail_a->ind - ps->min_ind);//
				tmp = a->next; //
			}
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
	else
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
}*/
void 	scrolling(t_ps *ps, t_num *a, int k)
{
	while (ps->tail_a->flag_b != -1 && k != 0)
	{
		if (ps->head_b->ind != ps->min_ind)
			rrr_exec(ps, ps->tail_a, ps->tail_b, "rrr");
		else
			rrr_exec(ps, ps->tail_a, ps->tail_b, "rra");
		ps->kol++;
		ps->sum++;
	}
}

void	more_than_five_alg(t_ps *ps, t_num *a, t_num *b, int k)
{
	/*if (k == 0 && ps->tail_a->ind == 0)
		ps->tail_a->flag_b = -1;*/
	some_valid(ps);
	from_a_to_b(ps, a, k);
	min_search(ps, ps->head_b, -1);
	scrolling(ps, a, k);
	/*while (ps->tail_a->flag_b != -1 && k != 0)
	{
		if (ps->head_b->ind != ps->min_ind)
			rrr_exec(ps, ps->tail_a, ps->tail_b, "rrr");
		else
			rrr_exec(ps, ps->tail_a, ps->tail_b, "rra");
		ps->kol++;
		ps->sum++;
	}*/
	sort_b(ps, a, b, 0);
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d flag_b %d\n", a->data, a->ind, a->flag_b);
		a = a->next;
	}
	printf ("!!!!\n\n");
	while (ps->flag > 0)
	{
		some_valid(ps); // нужна ли?
		//count_search(ps, ps->head_a, 0);
		/*if (ps->count_a == 5)
			for_five_el_alg(ps, a, b);
		if (ps->count_a == 4)
			for_four_el_alg(ps, a, b, 0);*/
	//	if (ps->count_a == 3)
		/*if (ps->count_a == 2)
			for_two_el_alg(ps, a, b);*/
	//	else
			from_a_to_b(ps, a, k);
	/*	b = ps->head_b;
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		while (b != NULL)
		{
			printf("data %d ind %d flag_b %d\n", b->data, b->ind, b->flag_b);
			b = b->next;
		}
		printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");*/
		if (ps->head_b)
			sort_b(ps, a, b, 1);
		if (ps->flag > ps->head_a->flag_b)
		    ps->flag--;
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d flag_b %d\n", a->data, a->ind, a->flag_b);
		a = a->next;
	}
	printf("\n\n\n");
	some_valid(ps);
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
	if (ac == 6)
		for_five_el_alg(ps, a, b);
	if (ac == 5)
		for_four_el_alg(ps, a, b, 0);
	if (ac == 4)
		for_three_el_alg(ps, a, b, 0);
	if (ac == 3)
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
		if (check_ind(ps, ps->head_a) == -1)
			return (0);
		if (check_start_sort(ps, ps->head_a) == 1)
			return (0);
		start_alg(ac, ps, ps->head_a, ps->head_b);
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
	}
	printf ("\nsum = %d\n", ps->sum);
	check_sort(ps, ps->head_a);
	return (0);
}