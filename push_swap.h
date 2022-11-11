/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkohki <kkohki@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 02:40:18 by kkohki            #+#    #+#             */
/*   Updated: 2022/04/20 05:30:48 by kkohki           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

typedef struct s_lst
{
	struct s_lst	*next;
	struct s_lst	*prev;
	long			num;
	bool			is_dummy;
	bool			is_compression;
	long			size;
}			t_lst;

//compression.c
long	search_min(t_lst *dummy);
size_t	log_two(long i);
size_t	dlst_size(t_lst *dummy);
void	compress_pre(t_lst *dummy);
//op_list.c
t_lst	*dlst_new(void);
void	dlst_add_back(t_lst *dummy, long num);
void	dlst_add_front(t_lst *dummy, long num);
void	dlst_del_back(t_lst *dummy);
void	dlst_del_front(t_lst *dummy);
//main.c
void	dlst_clear(t_lst *dummy);
void	print_dlst(t_lst *ls);
void	clear_all(t_lst *a, t_lst *b);
//op_rotate.c
void	ra(t_lst *a, t_lst *b);
void	rb(t_lst *a, t_lst *b);
void	rr(t_lst *a, t_lst *b);
//op_r_rotate.c
void	rra(t_lst *a, t_lst *b);
void	rrb(t_lst *a, t_lst *b);
void	rrr(t_lst *a, t_lst *b);
//op_swap.c
void	sa(t_lst *a, t_lst *b);
void	sb(t_lst *a, t_lst *b);
void	ss(t_lst *a, t_lst *b);
//op_push.c
void	pa(t_lst *a, t_lst *b);
void	pb(t_lst *a, t_lst *b);
//utils_one.c
size_t	ft_strlen(const char *s);
void	ft_putstr(char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
//utils_two.c
int		ft_atoi(const char *str);
void	ft_putchar(int c);
void	ft_putnbr(int n);
//error_treat.c
void	put_error(char *str);
int		ft_isdigit(int c);
int		ft_isnum(char *num);
int		check_dup(char **args, int num, int i);
void	check_args(char **args);
//sort_case.c
void	is_sorted(t_lst *a, t_lst *b);
void	sort_case_two(t_lst *a, t_lst *b);
void	sort_case_two_b(t_lst *a, t_lst *b);
void	sort_case_three(t_lst *a, t_lst *b);
void	sort_case_four(t_lst *a, t_lst *b);
//sort_case_other.c
void	sort_case_five(t_lst *a, t_lst *b);
void	sort_case_over_six(t_lst *a, t_lst *b);
#endif