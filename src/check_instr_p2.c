/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr_p2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 19:16:44 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:06:52 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void 	s_exec_b(t_ps *ps, t_num *a, t_num *b, char *line)
{
	if (b->next)
	{
		if (b->next->next)
			b->next->next->prev = b;
		ps->head_b = b->next;
		b->next = b;
		b->prev = ps->head_b;
		ps->head_b->prev = NULL;
		b->next = ps->head_b->next;
		ps->head_b->next = b;
	}
}

void 	s_exec(t_ps *ps, t_num *a, t_num *b, char *line)
{
	if (ft_strnequ(line, "sa", 3) || ft_strnequ(line, "ss", 3))
	{
		if (a->next)
		{
			if (a->next->next)
				a->next->next->prev = a;
			ps->head_a = a->next;
			a->next = a;
			a->prev = ps->head_a;
			ps->head_a->prev = NULL;
			a->next = ps->head_a->next;
			ps->head_a->next = a;
		}
	}
	if (ft_strnequ(line, "sb", 3) || ft_strnequ(line, "ss", 3))
		s_exec_b(ps, a, b, line);
}

void	p_exec_b(t_ps *ps, t_num *a, t_num *b, char *line)
{
	if (a)
	{
		ps->head_a = a->next;
		if (b)
			ps->head_b->prev = a;
		a->next = ps->head_b;
		ps->head_b = a;
		if (!b)
			ps->tail_b = ps->head_b;
		if (ps->head_a)
			ps->head_a->prev = NULL;
	}
}

void	p_exec(t_ps *ps, t_num *a, t_num *b, char *line)
{
	if (ft_strnequ(line, "pa", 3))
	{
		if (b)
		{
			ps->head_b = b->next;
			if (a)
				ps->head_a->prev = b;
			b->next = ps->head_a;
			ps->head_a = b;
			if (!a)
				ps->tail_a = ps->head_a;
			if (ps->head_b)
				ps->head_b->prev = NULL;
		}
	}
	else if (ft_strnequ(line, "pb", 3))
		p_exec_b(ps, a, b, line);
}