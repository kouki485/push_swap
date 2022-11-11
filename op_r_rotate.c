/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:40:06 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/15 04:32:40 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 10	30
// 20	10
// 30	20
// --	--
// a	a
// dummy <-> 10 <-> 20 <-> 30 <-> 40
// dummy <-> 40 <-> 10 <-> 20 <-> 30

void	rra(t_lst *a, t_lst *b)
{
	t_lst	*end;

	(void)b;
	end = a->prev;
	if (end->is_dummy)
		return ;
	dlst_add_front(a, end->num);
	dlst_del_back(a);
	ft_putstr("rra\n");
}

void	rrb(t_lst *a, t_lst *b)
{
	t_lst	*end;

	(void)a;
	end = b->prev;
	if (end->is_dummy)
		return ;
	dlst_add_front(b, end->num);
	dlst_del_back(b);
	ft_putstr("rrb\n");
}

void	rrr(t_lst *a, t_lst *b)
{
	rra(a, b);
	rrb(a, b);
	ft_putstr("rrr\n");
}
