/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:39:59 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/20 05:31:01 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dlst_clear(t_lst *dummy)
{
	t_lst	*now;

	now = dummy->next;
	while (!now->is_dummy)
	{
		now = now->next;
		free(now->prev);
	}
	free(now);
}

void	print_dlst(t_lst *ls)
{
	ls = ls->next;
	while (!ls->is_dummy)
	{
		ft_putnbr(ls->num);
		ft_putstr("\n");
		ls = ls->next;
	}
}

void	clear_all(t_lst *a, t_lst *b)
{
	dlst_clear(a);
	dlst_clear(b);
}

int	main(int argc, char **argv)
{
	t_lst	*a;
	t_lst	*b;
	int		i;

	a = dlst_new();
	b = dlst_new();
	check_args(argv);
	if (argc <= 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (argc > i)
		dlst_add_back(a, ft_atoi(argv[i++]));
	compress_pre(a);
	is_sorted(a, b);
	if ((argc - 1) == 2)
		sort_case_two(a, b);
	if ((argc - 1) == 3)
		sort_case_three(a, b);
	if ((argc - 1) == 4)
		sort_case_four(a, b);
	if ((argc - 1) == 5)
		sort_case_five(a, b);
	if ((argc - 1) >= 6)
		sort_case_over_six(a, b);
	clear_all(a, b);
}
