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

	while (tmp)
	{
		new = tmp->next;
		tmp->prev = NULL;
		tmp->next = NULL;
		free(tmp);
		tmp = new;
	}
	free(tmp);
}

void	free_t_ps(t_ps *ps)
{
	free_t_num(ps->head_a);

}