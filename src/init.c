/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:42:34 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:07:23 by emaveric         ###   ########.fr       */
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
	new->head_a = NULL; // почему было закоменчено?
	new->head_b = NULL;
	new->tail_a = NULL;
	new->tail_b = NULL;
	new->flag = 0;
	new->flag_v = 0;
	new->max = 0;
	new->mid = 0;
	new->min = 0;
	new->kol = 1;
	new->sum = 0;
	new->min_ind = -1;
	new->count_a = 0;
	new->count_b = 0;
	//new->head_a = init_num();
	return (new);
}

int			init_new(t_num **a, t_ps **ps)
{
	if (!(*a = init_num()))
	{
		write(2, "Error\n", 6);
		return (-1);
	}
	if (!(*ps = init_ps()))
	{
		free(*a);
		write(2, "Error\n", 6);
		return (-1);
	}
	return (1);
}
