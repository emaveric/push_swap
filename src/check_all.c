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

int		check_ind(t_ps *ps, t_num *a)
{
	int		min;
	int 	m_ind;
	t_num	*flag;

	a = ps->head_a;
	min = a->data;
	flag = a;
	m_ind = 0;
	while (a)
	{
		if (min > a->data && a->ind == -1)
		{
			min = a->data;
			flag = a;
		}
		ps->max = a->data;
		if (check_rep_value(ps->head_a, a->data, a->ind) == -1)
		{
			printf("Error");
			return (-1);
		}
		a = a->next;
		if (a == NULL && flag != NULL)
		{
			flag->ind = m_ind;
			if (m_ind == 0)
				ps->min = flag->data;
			m_ind++;
			flag = NULL;
			a = ps->head_a;
			min = 2147483647;
		}
	}
	return (0);
}

int		check_num(t_ps *ps, t_num *a, char **av)
{
	t_num	*tmp;
	int 	minus;

	tmp = a;
	av += 1;
	minus = 0;
	while (*av != NULL)
	{
		while (*av && **av)
		{
			if (**av == '-')
			{
				*av += 1;
				minus = 1;
			}
			if (**av >= '0' && **av <= '9')
			{
				if (ft_atoi(*av) < -2147483648 || ft_atoi(*av) > 2147483647)
					return (-1);
				a->data = ft_atoi(*av);
				if (minus == 1)
				{
					a->data *= -1;
					minus = 0;
				}
				if (a->next == NULL && a->prev == NULL/*ps->head_a == NULL*/)
					ps->head_a = a;
				a->ind = -1;
				if (*(av + 1))
				{
					if (!(a->next = init_num()))
						return (-1);
					//printf("data %d ind %d\n", a->data, a->ind);
					a = a->next;
					tmp->next = a;
					a->prev = tmp;
					tmp = a;
				}
				*av += 1;
				if (**av != ' ')
					av++;
			}
			else if (**av == ' ' && minus == 0)
				*av += 1;
			else
			{
				printf("Error\n");
				return (-1);
			}
			while (*av && **av && **av == ' ')
				*av += 1;
		}
		//av++;
	}
	a->next = NULL;
	ps->tail_a = a;
	return (0);
}