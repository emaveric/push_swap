/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:16:44 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/07 18:25:20 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 	s_exec(t_ps *ps, t_num *a, t_num *b, char *line)
{
	a = ps->head_a;
	b = ps->head_b;
	if (ft_strnequ(line, "sa", 3) || ft_strnequ(line, "ss", 3))
	{
		if (a->next)
		{
			ps->head_a = a->next;
			a->next = a;
			a->prev = ps->head_a;
			ps->head_a->prev = NULL;
			a->next = ps->head_a->next;
			ps->head_a->next = a;
		}
	}
	if (ft_strnequ(line, "sb", 3) || ft_strnequ(line, "ss", 3))
	{
		if (b->next)
		{
			ps->head_b = b->next;
			b->next = b;
			b->prev = ps->head_b;
			ps->head_b->prev = NULL;
			b->next = ps->head_b->next;
			ps->head_b->next = b;
		}
	}
}

void	p_exec(t_ps *ps, t_num *a, t_num *b, char *line)
{
	if (ft_strnequ(line, "pa", 3))
	{
		b = ps->head_b;
		if (b->ind != -1)
		{
			ps->head_b = b->next;
			ps->head_a->prev = b;
			b->next = ps->head_a;
			ps->head_a = b;
			ps->head_b->prev = NULL;
		}
	}
	else if (ft_strnequ(line, "pb", 3))
	{
		a = ps->head_a;
		if (a->ind != -1)
		{
			ps->head_a = a->next;
			ps->head_b->prev = a;
			a->next = ps->head_b;
			ps->head_b = a;
			ps->head_a->prev = NULL;
		}
	}
}

void	rr_exec(t_ps *ps, t_num *a, t_num *b, char *line)
{
	a = ps->head_a;
	b = ps->head_b;
	if ((ft_strnequ(line, "ra", 3) || ft_strnequ(line, "rr", 3))
		&& a->ind != -1)
	{
		ps->head_a = a->next;
		ps->tail_a->next = a;
		a->prev = ps->tail_a;
		ps->tail_a = a;
		a->next = NULL;
		ps->head_a->prev = NULL;
	}
	if ((ft_strnequ(line, "rb", 3) || ft_strnequ(line, "rr", 3))
		&& b->ind != -1)
	{
		ps->head_b = b->next;
		ps->tail_b->next = b;
		b->prev = ps->tail_b;
		ps->tail_b = b;
		b->next = NULL;
		ps->head_b->prev = NULL;
	}
}

void	rrr_exec(t_ps *ps, t_num *a, t_num *b, char *line)
{
	a = ps->tail_a;
	b = ps->tail_b;
	if ((ft_strnequ(line, "rra", 4) || ft_strnequ(line, "rrr", 4))
		&& a->ind != -1)
	{
		ps->tail_a = a->prev;
		ps->head_a->prev = a;
		a->next = ps->head_a;
		ps->head_a = a;
		a->prev = NULL;
		ps->tail_a->next = NULL;
	}
	if ((ft_strnequ(line, "rrb", 4) || ft_strnequ(line, "rrr", 4))
		&& b->ind != -1)
	{
		ps->tail_b = b->prev;
		ps->head_b->prev = b;
		b->next = ps->head_b;
		ps->head_b = b;
		b->prev = NULL;
		ps->tail_b->next = NULL;
	}
}

void	instr_execution(t_ps *ps, t_num *a, t_num *b, char *line)
{
	if (ft_strnequ(line, "s", 1))
		s_exec(ps, a, b, line);
	else if (ft_strnequ(line, "p", 1))
		p_exec(ps, a, b, line);
	else if (ft_strnequ(line, "r", 1) && ft_strlen(line) == 2)
		rr_exec(ps, a, b, line);
	else
		rrr_exec(ps, a, b, line);
}