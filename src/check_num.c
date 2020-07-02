/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 16:42:34 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/16 16:07:23 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char 	**check_atoi(t_ps *ps, t_num *a, char **av, int minus)
{
	t_num	*tmp;

	tmp = a;
	if (ft_atoi_max_int(&a->data, *av) == -1)
		return (NULL);
	a->data = ft_atoi(*av);
	if (minus == 1)
		a->data *= -1;
	minus = 0;
	if (a->next == NULL && a->prev == NULL)//ps->head_a == NULL)
		ps->head_a = a;
	a->ind = -1;
	if (*(av + 1))
	{
		if (!(a->next = init_num()))
			return (NULL);
		//printf("data %d ind %d\n", a->data, a->ind);
		a = a->next;
		tmp->next = a;
		a->prev = tmp;
		tmp = a;
	}
	*av += 1;
	if (**av != ' ')
		av++;
	return (av);
}

char	**check_num_main(t_ps *ps, t_num *a, char **av, int minus)
{
	while (*av && **av)
	{
		if (**av == '-' && ft_strcmp(*av, "-2147483648") != 0)
		{
			*av += 1;
			minus = 1;
		}
		if ((**av >= '0' && **av <= '9') || ft_strcmp(*av, "-2147483648") == 0)
		{
			if ((av = check_atoi(ps, a, av, minus)) == NULL)
				return (NULL);
			if (a->next)
				a = a->next;
			minus = 0;
		}
		else if (**av == ' ' && minus == 0)
			*av += 1;
		else
			/*	{
					printf("Error\n");*/
			return (NULL);
		//	}
		while (*av && **av && **av == ' ')
			*av += 1;
	}
	a->next = NULL;
	ps->tail_a = a;
	return (av);
}

int		check_num(t_ps *ps, t_num *a, char **av)
{
	int 	minus;

	av += 1;
	minus = 0;
	while (*av != NULL)
	{
		if ((av = check_num_main(ps, a, av, minus)) == NULL)
		{
			write(2, "Error\n", 6);
			free_t_ps(&ps, &a);
			return (-1);
		}
	}
	return (0);
}