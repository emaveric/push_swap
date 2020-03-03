/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:38:32 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/03 21:47:05 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_num	*init_num(void)
{
	t_num *new;

	if (!(new = (t_num *)malloc(sizeof(t_num))))
		return (NULL);
	new->data = 0;
	new->ind = -1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_ps	*init_ps(void)
{
	t_ps	*new;

	if (!(new = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	new->head_a = NULL;
	new->tail_a = NULL;
	new->head_b = NULL;
	new->tail_b = NULL;
	return (new);
}

int 	check_valid(void)
{
	return (0);
}

void	check_ind(t_ps *ps, t_num *a)
{
	int		min;
	int 	m_ind;
	t_num	*flag;

	a = ps->head_a;
	min = a->data;
	flag = a;
	m_ind = 0;
	while (a->next != NULL)
	{
		if (min > a->data && a->ind == -1)
		{
			min = a->data;
			flag = a;
		}
		a = a->next;
		if (a->next == NULL && flag != NULL)
		{
			flag->ind = m_ind;
			m_ind++;
			flag = NULL;
			a = ps->head_a;
			min = 2147483647;

		}
	}
}

void	check_num(t_ps *ps, t_num *a, char **av)
{
	t_num	*tmp;

	tmp = a;
	av += 1;
	while (*av != NULL)
	{
		while (**av)
		{
			if (**av == ' ')
				*av += 1;
			else if (**av >= '0' && **av < '9')
			{
				if (ft_atoi(*av) < -2147483648 || ft_atoi(*av) > 2147483647)
					return ;
				a->data = ft_atoi(*av);
				if (ps->head_a == NULL)
					ps->head_a = a;
				a->ind = -1;
				a->next = init_num();
				a = a->next;
				tmp->next = a;
				a->prev = tmp;
				tmp = a;
				*av += 1;
			}
			//printf("%c\n", **av);
			while (**av == ' ' && **av)
				*av += 1;
		}
		av++;
	}
	a->next = NULL;
	ps->tail_a = a;
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
		check_num(ps, a, av);
		check_ind(ps, a);
	}
	a = ps->head_a;
	while (a->next != NULL)
	{
		printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
	}
	return (0);
}