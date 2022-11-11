/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case_other.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 05:12:04 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/20 05:12:05 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_case_five(t_lst *a, t_lst *b)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (a->next->num == 0 || a->next->num == 1)
		{
			pb(a, b);
		}
		else
			ra(a, b);
		i++;
	}
	sort_case_three(a, b);
	sort_case_two_b(a, b);
	pa(a, b);
	pa(a, b);
}

void	sort_case_over_six(t_lst *a, t_lst *b)
{
	size_t	i;
	size_t	size;
	size_t	j;

	i = 0;
	j = log_two(dlst_size(a));
	while (i < j)
	{
		size = dlst_size(a);
		while (size--)
		{
			if ((a->next->num >> i) & 1)
				ra(a, b);
			else
				pb(a, b);
		}
		while (dlst_size(b))
			pa(a, b);
		i++;
	}
}
