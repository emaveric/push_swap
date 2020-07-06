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
		if (*line == '\0')
		{
			free(line);
			break ;
		}
		if (check_valid_instr(line) == 0)
		{
			if (line)
				free(line);
			line = NULL;
			return (0);
		}
		instr_execution(ps, line, 1);
		if (line)
			free(line);
		line = NULL;
	}
	return (1);
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

/*int		main(int ac, char **av)
{
	t_num	*a;
	t_ps	*ps;

	if (init_new(&a, &ps) == -1)
		return (0);
	if (ac < 2 || *av[1] == '\0')
	{
		free_t_ps(&ps, &a);
		return (0);
	}
	else
	{
		if (is_flag(&ac, av, &ps))
			av += 1;
		if (check_num(ps, a, av) == -1)
			return (0);
		if (check_ind(ps, a) == -1)
			return (0);
		if (read_instr(ps) == 0)
			write(2, "Error\n", 6);
		else
			check_sort(ps, a);
	}
	free_t_ps(&ps, &a);
	exit(0);
}*/
