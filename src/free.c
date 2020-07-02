/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 17:23:50 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/07 17:41:01 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_t_num(t_num *tmp)
{
	t_num *new;

	if (tmp)
	{
		while (tmp)
		{
			new = tmp->next;
			tmp->data = 0;
			tmp->ind = 0;
			tmp->flag_b = 0;
			tmp->prev = NULL;
			tmp->next = NULL;
			free(tmp);
			tmp = new;
		}
	}
}

void	free_t_ps(t_ps **ps, t_num **a)
{
	if ((*ps)->head_a)
		free_t_num((*ps)->head_a);
	if ((*ps)->head_b)
		free_t_num((*ps)->head_b);
	if (*a && (*ps)->head_a == NULL && (*ps)->head_b == NULL)
		free(*a);
	(*ps)->tail_a = NULL;
	(*ps)->tail_b = NULL;
	(*ps)->flag = 0;
	(*ps)->flag_v = 0;
	(*ps)->max = 0;
	(*ps)->mid = 0;
	(*ps)->min = 0;
	(*ps)->min_ind = 0;
	(*ps)->kol = 0;
	(*ps)->count_a = 0;
	(*ps)->count_b = 0;
	(*ps)->sum = 0;
	free(*ps);
	*ps = NULL;
}
