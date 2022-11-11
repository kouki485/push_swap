/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_treat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 06:08:24 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/16 04:51:34 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_error(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
	exit(0);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_isnum(char *num)
{
	int	i;
	int	count_num;

	i = 0;
	count_num = 0;
	while (num[i] == '-' || num[i] == '+')
	{
		i++;
		if (i == 2)
			return (0);
	}
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		count_num++;
		i++;
	}
	if (!count_num)
		return (0);
	return (1);
}

int	check_dup(char **args, int num, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

void	check_args(char **args)
{
	int	i;
	int	num;

	i = 1;
	while (args [i])
	{
		if (!ft_isnum(args[i]))
			put_error("Error");
		num = ft_atoi(args[i]);
		if (check_dup(args, num, i))
			put_error("Error");
		i++;
	}
}
