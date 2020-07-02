/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:38:32 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:14:21 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		read_instr(t_ps *ps)
{
	char	*line;

	if (ps->flag_v == 1)
		output_stacks(&ps);
	while (get_next_line(0, &line))
	{
		if (!(check_valid_instr(line)))
		{
			printf("Error\n");
			free(line);
			return (-1);
		}
		instr_execution(ps, line);
		free(line);
	}
	return (0);
}

int		is_flag(int *ac, char **av, t_ps **ps)
{
	if (!ft_strcmp("-v", *(av + 1)))
	{
		(*ps)->flag_v = 1;
		*ac -= 1;
		return (1);
	}
	return (0);
}

int 	main(int ac, char **av)
{
	t_num	*a;
	t_num	*b;
	t_ps	*ps;

	if (!(ps = init_ps()))
		return (-1);
	if (ac > 1)
	{
		if (!(a = init_num()))
			return (-1);
		if (!(b = init_num()))
			return (-1);
		if (is_flag(&ac, av, &ps))
			av += 1;
		if (check_num(ps, a, av) == -1)
			return (0);
		check_ind(ps, a);
		a = ps->head_a;
		while (a != NULL)
		{
			printf("data %d ind %d\n", a->data, a->ind);
			a = a->next;
		}
		read_instr(ps);
		check_sort(ps, a);
		/*a = ps->head_a;
		free_t_num(a);
		free_t_num(ps->head_b);
		free(ps);*/
		// почистить списки нормально !!!!!!!!!!!!!!!!!!!!!!!!!!!!
	}
	a = ps->head_a;
	while (a != NULL)
	{
		printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
	}
	return (0);
}
