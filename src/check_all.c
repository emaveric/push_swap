/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:42:34 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:07:23 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_sort(t_ps *ps, t_num *a)
{
	int		ind;

	ind = 0;
	a = ps->head_a;
	if (ps->head_b != NULL || ps->head_a == NULL)
	{
		ft_printf("KO\n");
		return (0);
	}
	while (a)
	{
		if (ind != a->ind)
		{
			ft_printf("KO\n");
			return (0);
		}
		ind++;
		a = a->next;
	}
	ft_printf("OK\n");
	return (0);
}

int		check_ind_main(t_ps *ps, t_num *a, int m_ind, t_num *flag)
{
	ps->min = a->data;
	while (a)
	{
		if (ps->min >= a->data && a->ind == -1)
		{
			ps->min = a->data;
			flag = a;
		}
		ps->max = a->data;
		if (check_rep_value(ps->head_a, a->data, a->ind) == -1)
			return (-1);
		a = a->next;
		if (a == NULL && flag != NULL)
		{
			flag->ind = m_ind;
			if (m_ind == 0)
				ps->min = flag->data;
			m_ind++;
			flag = NULL;
			a = ps->head_a;
			ps->min = 2147483647;
		}
	}
	return (0);
}

int		check_ind(t_ps *ps, t_num *a)
{
	int				m_ind;
	t_num			*flag;

	a = ps->head_a;
	flag = a;
	m_ind = 0;
	if (check_ind_main(ps, a, m_ind, flag) == -1)
	{
		write(2, "Error\n", 6);
		free_t_ps(&ps, &a);
		return (-1);
	}
	ps->min = 0;
	return (0);
}
