/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:38:32 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/13 17:10:08 by emaveric         ###   ########.fr       */
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
	new->flag_b = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_ps	*init_ps(void)
{
	t_ps	*new;

	if (!(new = (t_ps *)malloc(sizeof(t_ps))))
		return (NULL);
	/*new->head_a = NULL;*/
	new->head_b = NULL;
	new->tail_a = NULL;
	new->tail_b = NULL;
	new->flag = 0;
	new->max = 0;
	new->mid = 0;
	new->min = 0;
	new->kol = 6;
	new->count_a = 0;
	new->count_b = 0;
	new->head_a = init_num();
	/*new->tail_a = init_num();
	new->head_b = init_num();
	new->tail_b = init_num();*/
	return (new);
}

int		read_instr(t_ps *ps, t_num *a, t_num *b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (!(check_valid_instr(line)))
		{
			printf("Error\n");
			free(line);
			return (-1);
		}
		instr_execution(ps, a, b, line);
		free(line);
	}
	return (0);
}

/*
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
		a = ps->head_a;
		while (a != NULL)
		{
			printf("data %d ind %d\n", a->data, a->ind);
			a = a->next;
		}
		read_instr(ps, a, b);
		check_sort(ps, a);
		a = ps->head_a;
		free_t_num(a);
		free_t_num(ps->head_b);
		free(ps);
		// почистить списки нормально !!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
	}
	return (0);
}*/
