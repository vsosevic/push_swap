/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:40:15 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/09 12:43:29 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct	s_stack
{
	int			*nbrs;
	int			nbrs_l;
	char		name;
}				t_stack;

void			create_stacks(int *nbrs, int nbrs_len, t_stack *a, t_stack *b);
void			print_stacks(t_stack *a, t_stack *b, int argc);
int				*nbrs_from_argv(char **argv, int n);
void			shift_down(t_stack *stk);
void			shift_up(t_stack *stk);
void			swap_sx(t_stack *stk, char **cmds);
void			swap_ss(t_stack *a, t_stack *b, char **cmds);
void			push_a(t_stack *a, t_stack *b, char **cmds);
void			push_b(t_stack *a, t_stack *b, char **cmds);
void			rotate_rx(t_stack *stk, char **cmds);
void			rotate_rr(t_stack *a, t_stack *b, char **cmds);
void			rotate_rrx(t_stack *stk, char **cmds);
void			rotate_rrr(t_stack *a, t_stack *b, char **cmds);
int				ft_atoi_modified(const char *str);
void			ft_exit(char *error_message);
void			bubble_sort(int *arr, int n);
void			stk_bubble_sort(t_stack *a, t_stack *b, char **cmds);
int				stk_a_is_sorted(t_stack *a, int n);
int				stk_b_is_sorted(t_stack *b, int n);
void			sort_3a(t_stack *a, int n, char **cmds);
void			sort_3b(t_stack *a, t_stack *b, int n, char **cmds);
void			pa_pa_pa(t_stack *a, t_stack *b, char **cmds);
int				med_push_from_to(t_stack *from, t_stack *to, int n,
									char **cmds);
void			quicksort_a(t_stack *a, t_stack *b, int n, char **cmds);
void			quicksort_b(t_stack *a, t_stack *b, int n, char **cmds);
void			cmds_optimizer(char **str);
char			*ft_strjoin_m(char *s1, char const *s2);

#endif
