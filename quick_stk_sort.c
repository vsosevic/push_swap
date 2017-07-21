/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_stk_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 12:20:55 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/18 12:21:12 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quicksort_a(t_stack *a, t_stack *b, int n, char **cmds)
{
	int pushed;

	if (stk_a_is_sorted(a, n) == 1)
		return ;
	if (n > 3)
	{
		pushed = med_push_from_to(a, b, n, cmds);
		quicksort_a(a, b, n - pushed, cmds);
		quicksort_b(a, b, pushed, cmds);
	}
	else
		sort_3a(a, n, cmds);
}

void	quicksort_b(t_stack *a, t_stack *b, int n, char **cmds)
{
	int i;
	int pushed;

	if (stk_b_is_sorted(b, n) == 1)
	{
		i = 0;
		while (i < n)
		{
			push_a(a, b, cmds);
			i++;
		}
		return ;
	}
	if (n > 3)
	{
		pushed = med_push_from_to(b, a, n, cmds);
		quicksort_a(a, b, pushed, cmds);
		quicksort_b(a, b, n - pushed, cmds);
	}
	else
		sort_3b(a, b, n, cmds);
}
