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

int 	check_sort(t_ps *ps, t_num *a)
{
	int		ind;

	ind = 0;
	a = ps->head_a;
	//printf("\n\nhead_b: data %d ind %d\n\n", ps->head_b->data, ps->head_b->ind);
	while (a)
	{
		if (ind != a->ind)
		{
			printf("KO\n");
			printf("ind %d", a->ind);
			return (0);
		}
		ind++;
		a= a->next;
	}
	printf("OK\n");
	return (0);
}

int		check_ind_main(t_ps *ps, t_num *a, int m_ind, t_num *flag)
{
	long long		min;

	min = a->data;
	while (a)
	{
		if (min > a->data && a->ind == -1)
		{
			min = a->data;
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
			min = 2147483648;
		}
	}
	return (0);
}

int		check_ind(t_ps *ps, t_num *a)
{
	int 			m_ind;
	t_num			*flag;

	a = ps->head_a;
	flag = a;
	m_ind = 0;
	if (check_ind_main(ps, a, m_ind, flag) == -1)
	{
		printf("Error");
		return (-1);
	}
	return (0);
}
