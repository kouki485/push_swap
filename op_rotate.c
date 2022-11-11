/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:40:10 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/15 04:33:52 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 10	20
// 20	30
// 30	10
// --	--
// a	a
// dummy <-> 10 <-> 20 <-> 30 <-> 40
// dummy <-> 20 <-> 30 <-> 40 <-> 10

void	ra(t_lst *a, t_lst *b)
{
	t_lst	*first;

	(void)b;
	first = a->next;
	if (first->is_dummy)
		return ;
	dlst_add_back(a, first->num);
	dlst_del_front(a);
	ft_putstr("ra\n");
}

void	rb(t_lst *a, t_lst *b)
{
	t_lst	*first;

	(void)a;
	first = b->next;
	if (first->is_dummy)
		return ;
	dlst_add_back(b, first->num);
	dlst_del_front(b);
	ft_putstr("rb\n");
}

void	rr(t_lst *a, t_lst *b)
{
	ra(a, b);
	rb(a, b);
	ft_putstr("rr\n");
}
