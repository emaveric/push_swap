/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:40:56 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:30:10 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_search(t_ps *ps, t_num *n, int k)
{
	ps->min = 2147483647;
	ps->min_ind = -1;
	if (k == 0)
	{
		while (n)
		{
			if (ps->min > n->data && n->flag_b == 0)
				ps->min = n->data;
			n = n->next;
		}
	}
	else if (k == -1)
	{
		while (n)
		{
			if (ps->min > n->data)
			{
				ps->min = n->data;
				ps->min_ind = n->ind;
			}
			n = n->next;
		}
	}
	else
		while (k != 0)
		{
			if (ps->min > n->data)
				ps->min = n->data;
			n = n->next;
			k--;
		}
}

void	max_search(t_ps *ps, t_num *n)
{
	ps->max = -2147483648;
	while (n)
	{
		if (ps->max < n->data)
			ps->max = n->data;
		n = n->next;
	}
}

void	count_search(t_ps *ps, t_num *n, int k)
{
	if (k == 0)
	{
		while (n->flag_b == ps->flag)
		{
			ps->count_a++;
			n = n->next;
		}
	}
	else if (k == 1)
	{
		while (n)
		{
			ps->count_a++;
			n = n->next;
		}
	}
	else
	{
		while (n)
		{
			ps->count_b++;
			n = n->next;
		}
	}

}