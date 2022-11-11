/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:28:33 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/15 04:28:56 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//				80
// 10	80		10
// 20	90		20	90
// 30	100		30	100
// --	--		--	--
// a	b		a	b
//a(before): dummy <-> 10 <-> 20 <-> 30
//b(before): dummy <-> 80 <-> 90 <-> 100
//a(after) : dummy <-> 80 <-> 10 <-> 20 <-> 30
//b(after) : dummy <-> 90 <-> 100

void	pa(t_lst *a, t_lst *b)
{
	t_lst	*first;

	first = b->next;
	if (first->is_dummy)
		return ;
	dlst_add_front(a, first->num);
	dlst_del_front(b);
	ft_putstr("pa\n");
}

void	pb(t_lst *a, t_lst *b)
{
	t_lst	*first;

	first = a->next;
	if (first->is_dummy)
		return ;
	dlst_add_front(b, first->num);
	dlst_del_front(a);
	ft_putstr("pb\n");
}
