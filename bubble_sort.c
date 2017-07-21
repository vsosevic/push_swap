/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 12:18:39 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/15 12:27:42 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	bubble_sort(int *arr, int n)
{
	int i;
	int j;

	i = 0;
	while (i < n - 1)
	{
		j = 0;
		while (j < n - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

void	push_a_to_b(t_stack *a, t_stack *b, int min_pos, char **cmds)
{
	if (min_pos > a->nbrs_l / 2)
	{
		min_pos = a->nbrs_l - min_pos;
		while (min_pos > 0)
		{
			rotate_rrx(a, cmds);
			min_pos--;
		}
	}
	else
	{
		while (min_pos > 0)
		{
			rotate_rx(a, cmds);
			min_pos--;
		}
	}
	push_b(a, b, cmds);
}

void	stk_bubble_sort(t_stack *a, t_stack *b, char **cmds)
{
	int i;
	int min;
	int min_pos;

	while (a->nbrs_l > 0)
	{
		i = 0;
		min = 2147483647;
		while (i < a->nbrs_l)
		{
			if (a->nbrs[i] < min)
			{
				min = a->nbrs[i];
				min_pos = i;
			}
			i++;
		}
		push_a_to_b(a, b, min_pos, cmds);
	}
	while (b->nbrs_l > 0)
		push_a(a, b, cmds);
}
