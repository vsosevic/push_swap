/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:30:47 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/18 15:31:07 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rb_sb_pa_rrb_pa_pa(t_stack *a, t_stack *b, char **cmds)
{
	rotate_rx(b, cmds);
	swap_sx(b, cmds);
	push_a(a, b, cmds);
	rotate_rrx(b, cmds);
	push_a(a, b, cmds);
	push_a(a, b, cmds);
}

static void	rb_sb_pa_pa_rrb_pa(t_stack *a, t_stack *b, char **cmds)
{
	rotate_rx(b, cmds);
	swap_sx(b, cmds);
	push_a(a, b, cmds);
	push_a(a, b, cmds);
	rotate_rrx(b, cmds);
	push_a(a, b, cmds);
}

static void	sort_with_tail(t_stack *a, t_stack *b, char **cmds)
{
	if (b->nbrs[2] > (b->nbrs)[1] && (b->nbrs)[1] > (b->nbrs)[0])
		rb_sb_pa_pa_rrb_pa(a, b, cmds);
	else if (b->nbrs[2] > b->nbrs[0] && b->nbrs[0] > b->nbrs[1])
		rb_sb_pa_rrb_pa_pa(a, b, cmds);
	else if (b->nbrs[1] > b->nbrs[2] && b->nbrs[2] > b->nbrs[0])
	{
		swap_sx(b, cmds);
		push_a(a, b, cmds);
		swap_sx(b, cmds);
		push_a(a, b, cmds);
		push_a(a, b, cmds);
	}
	else if (b->nbrs[1] > b->nbrs[0] && b->nbrs[0] > b->nbrs[2])
	{
		swap_sx(b, cmds);
		pa_pa_pa(a, b, cmds);
	}
	else if (b->nbrs[0] > b->nbrs[2] && b->nbrs[2] > b->nbrs[1])
	{
		push_a(a, b, cmds);
		swap_sx(b, cmds);
		push_a(a, b, cmds);
		push_a(a, b, cmds);
	}
}

static void	sort_without_tail(t_stack *a, t_stack *b, char **cmds)
{
	if (b->nbrs[2] > b->nbrs[1] && b->nbrs[1] > b->nbrs[0])
	{
		swap_sx(b, cmds);
		rotate_rrx(b, cmds);
	}
	else if (b->nbrs[2] > b->nbrs[0] && b->nbrs[0] > b->nbrs[1])
		rotate_rrx(b, cmds);
	else if (b->nbrs[1] > b->nbrs[2] && b->nbrs[2] > b->nbrs[0])
		rotate_rx(b, cmds);
	else if (b->nbrs[1] > b->nbrs[0] && b->nbrs[0] > b->nbrs[2])
		swap_sx(b, cmds);
	else if (b->nbrs[0] > b->nbrs[2] && b->nbrs[2] > b->nbrs[1])
	{
		rotate_rrx(b, cmds);
		swap_sx(b, cmds);
	}
	pa_pa_pa(a, b, cmds);
}

void		sort_3b(t_stack *a, t_stack *b, int n, char **cmds)
{
	if (n < 2)
	{
		push_a(a, b, cmds);
		return ;
	}
	if (n == 2)
	{
		if (b->nbrs[0] < b->nbrs[1])
			swap_sx(b, cmds);
		push_a(a, b, cmds);
		push_a(a, b, cmds);
		return ;
	}
	if (b->nbrs[0] > b->nbrs[1] && b->nbrs[1] > b->nbrs[2])
		pa_pa_pa(a, b, cmds);
	else if (n == 3 && b->nbrs_l == 3)
		sort_without_tail(a, b, cmds);
	else
		sort_with_tail(a, b, cmds);
}
