/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:22:45 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/14 21:22:45 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int 	check_start_sort(t_ps *ps, t_num *a)
{
	int		ind;

	ind = 0;
	a = ps->head_a;
	while (a)
	{
		if (ind != a->ind)
			return (0);
		ind++;
		a= a->next;
	}
	printf("start sort");
	return (1);
}

int 	check_valid_instr(char *line)
{
	if (ft_strnequ(line, "sa", 3))
		return (1);
	else if (ft_strnequ(line, "sb", 3))
		return (1);
	else if (ft_strnequ(line, "sb", 3))
		return (1);
	else if (ft_strnequ(line, "ss", 3))
		return (1);
	else if (ft_strnequ(line, "pa", 3))
		return (1);
	else if (ft_strnequ(line, "pb", 3))
		return (1);
	else if (ft_strnequ(line, "ra", 3))
		return (1);
	else if (ft_strnequ(line, "rb", 3))
		return (1);
	else if (ft_strnequ(line, "rr", 3))
		return (1);
	else if (ft_strnequ(line, "rra", 4))
		return (1);
	else if (ft_strnequ(line, "rrb", 4))
		return (1);
	else if (ft_strnequ(line, "rrr", 4))
		return (1);
	return (0);
}

int 	check_rep_value(t_num *a, int data, int ind)
{
	while (a->next)
	{
		if (data == a->data && ind != a->ind)
			return (-1);
		a = a->next;
	}
	return (0);
}
