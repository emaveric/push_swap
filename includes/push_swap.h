/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaveric <emaveric@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:09:37 by emaveric          #+#    #+#             */
/*   Updated: 2020/03/03 18:25:33 by emaveric         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_PUSH_SWAP_H
# define PUSH_SWAP_PUSH_SWAP_H

# include <stdio.h>
# include <stdarg.h>
# include "../libft/libft.h"

typedef struct			s_num
{
	struct s_num		*next;
	struct s_num		*prev;
	int 				data;
	int 				ind;

}						t_num;

typedef struct			s_ps
{
	struct s_num		*head_a;
	struct s_num		*tail_a;
	struct s_num		*head_b;
	struct s_num		*tail_b;
}						t_ps;

#endif
