/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 18:40:56 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/12 19:53:50 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	min_search(t_ps *ps, t_num *n, int k)
{
	if (k == 0)
	{
		while (n)
		{
			if (ps->min > n->data)
				ps->min = n->data;
			n = n->next;
		}
	}
	else
	{
		while (k != 0)
		{
			if (ps->min > n->data)
				ps->min = n->data;
			n = n->next;
			k--;
		}
	}
}