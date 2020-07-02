/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:16:44 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:06:52 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rr_exec_b(t_ps *ps, t_num *b)
{
	ps->head_b = b->next;
	if (ps->tail_b)
		ps->tail_b->next = b;
	b->prev = ps->tail_b;
	ps->tail_b = b;
	b->next = NULL;
	ps->head_b->prev = NULL;
}

void	rr_exec(t_ps *ps, char *line, int k)
{
	t_num	*a;
	t_num	*b;

	a = ps->head_a;
	b = ps->head_b;
	if ((ft_strnequ(line, "ra", 3) || ft_strnequ(line, "rr", 3))
		&& a && a->next)
	{
		ps->head_a = a->next;
		if (ps->tail_a)
			ps->tail_a->next = a;
		a->prev = ps->tail_a;
		ps->tail_a = a;
		a->next = NULL;
		ps->head_a->prev = NULL;
	}
	if ((ft_strnequ(line, "rb", 3) || ft_strnequ(line, "rr", 3))
		&& b && b->next)
		rr_exec_b(ps, b);
	if (ft_strcmp(line, "ra") == 0 && k != 1)
		ft_printf("ra\n");
	else if (ft_strcmp(line, "rb") == 0 && k != 1)
		ft_printf("rb\n");
	else if (ft_strcmp(line, "rr\n") == 0 && k != 1)
		ft_printf("rr\n");
}

void	rrr_exec_b(t_ps *ps, t_num *b)
{
	ps->tail_b = b->prev;
	ps->head_b->prev = b;
	if (ps->head_b)
		b->next = ps->head_b;
	ps->head_b = b;
	b->prev = NULL;
	if (ps->tail_b)
		ps->tail_b->next = NULL;
}

void	rrr_exec(t_ps *ps, char *line, int k)
{
	t_num	*a;
	t_num	*b;

	a = ps->tail_a;
	b = ps->tail_b;
	if ((ft_strnequ(line, "rra", 4) || ft_strnequ(line, "rrr", 4))
		&& a && a->prev)
	{
		ps->tail_a = a->prev;
		ps->head_a->prev = a;
		if (ps->head_a)
			a->next = ps->head_a;
		ps->head_a = a;
		a->prev = NULL;
		if (ps->tail_a)
			ps->tail_a->next = NULL;
	}
	if ((ft_strnequ(line, "rrb", 4) || ft_strnequ(line, "rrr", 4))
		&& b && b->prev)
		rrr_exec_b(ps, b);
	if (ft_strcmp(line, "rra") == 0 && k != 1)
		ft_printf("rra\n");
	else if (ft_strcmp(line, "rrb") == 0 && k != 1)
		ft_printf("rrb\n");
	else if (ft_strcmp(line, "rrr") == 0 && k != 1)
		ft_printf("rrr\n");
}

void	instr_execution(t_ps *ps, char *line, int k)
{
	if (ft_strnequ(line, "s", 1))
		s_exec(ps, line, k);
	else if (ft_strnequ(line, "p", 1))
		p_exec(ps, line, k);
	else if (ft_strnequ(line, "r", 1) && ft_strlen(line) == 2)
		rr_exec(ps, line, k);
	else
		rrr_exec(ps, line, k);
	if (ps->flag_v == 1)
		output_stacks(&ps);
}