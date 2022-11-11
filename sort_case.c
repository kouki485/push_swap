/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 04:34:07 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/20 05:08:47 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	is_sorted(t_lst *a, t_lst *b)
{
	size_t	i;

	(void)b;
	i = dlst_size(a);
	while (i > 0)
	{
		if (a->next->num < a->num)
			return ;
		a = a->next;
		i--;
	}
	exit(EXIT_SUCCESS);
}

void	sort_case_two(t_lst *a, t_lst *b)
{
	(void)b;
	if (a->next->num > a->next->next->num)
		sa(a, b);
}

void	sort_case_two_b(t_lst *a, t_lst *b)
{
	(void)a;
	if (b->next->num < b->next->next->num)
		sb(a, b);
}

void	sort_case_three(t_lst *a, t_lst *b)
{
	long	first;
	long	second;
	long	third;

	first = a->next->num;
	second = a->next->next->num;
	third = a->next->next->next->num;
	if (first > second && second < third && first < third)
		sa(a, b);
	else if (first > second && second > third)
	{
		sa(a, b);
		rra(a, b);
	}
	else if (first > second && second < third && first > third)
		ra(a, b);
	else if (first < second && second > third && first < third)
	{
		sa(a, b);
		ra(a, b);
	}
	else if (first < second && second > third && first > third)
		rra(a, b);
}

void	sort_case_four(t_lst *a, t_lst *b)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (a->next->num == 0)
		{
			pb(a, b);
			break ;
		}
		else
			ra(a, b);
		i++;
	}
	sort_case_three(a, b);
	pa(a, b);
}
