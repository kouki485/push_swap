/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:40:14 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/16 04:33:15 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// 10	20
// 20	10
// 30	30
// --	--
// a	a
// dummy <-> 10 <-> 20 <-> 30 <-> 40
// dummy <-> 20 <-> 10 <-> 30 <-> 40

static void	swap(t_lst *lst1, t_lst *lst2)
{
	long	tmp;

	tmp = lst1->num;
	lst1->num = lst2->num;
	lst2->num = tmp;
}

void	sa(t_lst *a, t_lst *b)
{
	t_lst	*first;
	t_lst	*second;

	(void)b;
	first = a->next;
	second = first->next;
	if (first->is_dummy || second->is_dummy)
		return ;
	swap(first, second);
	ft_putstr("sa\n");
}

void	sb(t_lst *a, t_lst *b)
{
	t_lst	*first;
	t_lst	*second;

	(void)a;
	first = b->next;
	second = first->next;
	if (first->is_dummy || second->is_dummy)
		return ;
	swap(first, second);
	ft_putstr("sb\n");
}

void	ss(t_lst *a, t_lst *b)
{
	sa(a, b);
	sb(a, b);
	ft_putstr("ss\n");
}
