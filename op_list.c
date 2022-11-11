/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_list.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 04:24:28 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/15 05:25:45 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_lst	*dlst_new(void)
{
	t_lst	*new;

	new = ft_calloc(1, sizeof(t_lst));
	new->is_dummy = true;
	new->next = new;
	new->prev = new;
	return (new);
}

// prev <-> dummy <-> next
// prev <-> [add] <-> dummy <-> next

void	dlst_add_back(t_lst *dummy, long num)
{
	t_lst	*prev;
	t_lst	*next;
	t_lst	*new;

	prev = dummy->prev;
	next = dummy;
	new = ft_calloc(1, sizeof(t_lst));
	new->next = next;
	new->prev = prev;
	new->num = num;
	next->prev = new;
	prev->next = new;
}

// dummy->prev <-> dummy <-> dummy->next
// dummy->prev <-> dummy <-> [add] <-> dummy->next

void	dlst_add_front(t_lst *dummy, long num)
{
	t_lst	*prev;
	t_lst	*next;
	t_lst	*new;

	prev = dummy;
	next = dummy->next;
	new = ft_calloc(1, sizeof(t_lst));
	new->next = next;
	new->prev = prev;
	new->num = num;
	next->prev = new;
	prev->next = new;
}

// dummy <- dummy -> dummy
// prev <-> [target] <-> dummy <-> next
// prev <-> dummy <-> next

void	dlst_del_back(t_lst *dummy)
{
	t_lst	*target;
	t_lst	*next;
	t_lst	*prev;

	target = dummy->prev;
	if (target->is_dummy)
		return ;
	next = target->next;
	prev = target->prev;
	free(target);
	next->prev = prev;
	prev->next = next;
}

// prev <-> dummy <-> [target] <-> next
// prev <-> dummy <-> next

void	dlst_del_front(t_lst *dummy)
{
	t_lst	*target;
	t_lst	*next;
	t_lst	*prev;

	target = dummy->next;
	if (target->is_dummy)
		return ;
	next = target->next;
	prev = target->prev;
	free(target);
	next->prev = prev;
	prev->next = next;
}
