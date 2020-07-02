/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/14 21:22:45 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/14 21:22:45 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	stacks_print(t_ps **ps)
{
	t_num *tmp_a;
	t_num *tmp_b;

	tmp_a = (*ps)->head_a;
	tmp_b = (*ps)->head_b;
	while (tmp_a || tmp_b)
	{
		if (tmp_b == NULL && tmp_a)
		{
			ft_printf("%13i | %7c\n", tmp_a->data, ' ');
			tmp_a = tmp_a->next;
		}
		else if (tmp_a == NULL && tmp_b)
		{
			ft_printf("%13c | %1i\n", ' ', tmp_b->data);
			tmp_b = tmp_b->next;
		}
		else if (tmp_a && tmp_b)
		{
			ft_printf("%13i | %1i\n", tmp_a->data, tmp_b->data);
			tmp_a = tmp_a->next;
			tmp_b = tmp_b->next;
		}
	}
}

void	stacks_print_help(t_ps **ps)
{
	write(1, "\033[0d\033[2J", 8);
	stacks_print(ps);
	ft_printf("-----------------------------\n");
	ft_printf("%13s | %7s\n", "stack A", "stack B");
	ft_printf("-----------------------------\n");
}

void	output_stacks(t_ps **ps)
{
	if ((*ps)->flag_v == 1)
	{
		usleep(100500);
		stacks_print_help(ps);
	}
}
