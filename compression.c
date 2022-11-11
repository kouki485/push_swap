/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 04:24:37 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/16 04:56:07 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// dummy <-> 45 <-> 12 <-> 20 <-> 38
// dummy <-> 4 <-> 1 <-> 2 <-> 3

#include "push_swap.h"

long	search_min(t_lst *dummy)
{
	long	min;

	dummy = dummy->next;
	min = LONG_MAX;
	while (!dummy->is_dummy)
	{
		if (min > dummy->num && !dummy->is_compression)
			min = dummy->num;
		dummy = dummy->next;
	}
	return (min);
}

size_t	log_two(long i)
{
	size_t	j;

	j = 0;
	if (i == 0)
		return (1);
	while (i)
	{
		i /= 2;
		j++;
	}
	return (j);
}

size_t	dlst_size(t_lst *dummy)
{
	size_t	i;

	dummy = dummy->next;
	i = 0;
	while (!dummy->is_dummy)
	{
		dummy = dummy->next;
		i++;
	}
	dummy->size = i;
	return (i);
}

void	compress_pre(t_lst *dummy)
{
	t_lst		*first;
	size_t		now;
	size_t		i;
	size_t		j;

	i = 0;
	now = 0;
	while (i < dlst_size(dummy))
	{
		j = 0;
		first = dummy->next;
		while (j < dlst_size(dummy))
		{
			if (!first->is_compression && search_min(dummy) == first->num)
			{
				first->num = now;
				first->is_compression = true;
				break ;
			}
			first = first->next;
			j++;
		}
		now++;
		i++;
	}
}
