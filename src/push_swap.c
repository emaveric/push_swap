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

void	scrolling(t_ps *ps, int k)
{
	while (ps->tail_a->flag_b != -1 && k != 0)
	{
		if (ps->head_b->ind != ps->min_ind)
			rrr_exec(ps, "rrr", 0);
		else
			rrr_exec(ps, "rra", 0);
		ps->kol++;
	}
}

void	more_than_five_alg(t_ps *ps, t_num *a, t_num *b, int k)
{
	some_valid(ps);
	from_a_to_b(ps, a, k);
	min_search(ps, ps->head_b, -1);
	scrolling(ps, k);
	sort_b(ps, a, b, 0);
	a = ps->head_a;
	while (ps->flag > 0)
	{
		some_valid(ps);
		from_a_to_b(ps, a, k);
		if (ps->head_b)
			sort_b(ps, a, b, 1);
		if (ps->flag > ps->head_a->flag_b)
			ps->flag--;
	}
	some_valid(ps);
	if (ps->kol > 0)
	{
		ps->kol = 0;
		more_than_five_alg(ps, a, b, ++k);
	}
}

void	start_alg(t_ps *ps, t_num *a, t_num *b)
{
	int		kol;

	kol = ps->kol;
	ps->kol = 0;
	if (kol > 6)//if (ac > 6)
		more_than_five_alg(ps, a, b, 0);
	if (kol == 6)//if (ac == 6)
		for_five_el_alg(ps, a);
	if (kol == 5)//if (ac == 5)
		for_four_el_alg(ps, a, 0);
	if (kol == 4)//if (ac == 4)
		for_three_el_alg(ps, a, 0);
	if (kol == 3)//if (ac == 3)
		for_two_el_alg(ps, a);
}

int		main(int ac, char **av)
{
	t_num	*a;
	t_ps	*ps;

	if (init_new(&a, &ps) == -1)
		return (0);
	if (ac < 2 || *av[1] == '\0')
	{
		ft_printf("Usage: ./push_swap [arg_1] [arg_2]...arg[n]\n");
		free_t_ps(&ps, &a);
		return (0);
	}
	if (ac > 1)
	{
		if (check_num(ps, a, av) == -1)
			return (0);
		if (check_ind(ps, a) == -1)
			return (0);
		if (check_start_sort(ps, a) == 1)
			return (0);
		start_alg(ps, a, ps->head_b);
	}
/*	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
	}*/
	free_t_ps(&ps, &a);
	exit(0);
}
