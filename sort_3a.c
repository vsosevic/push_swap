/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 15:30:47 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/18 15:31:07 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		pa_pa_pa(t_stack *a, t_stack *b, char **cmds)
{
	push_a(a, b, cmds);
	push_a(a, b, cmds);
	push_a(a, b, cmds);
}

static void	ra_sa_rra_sa(t_stack *a, char **cmds)
{
	rotate_rx(a, cmds);
	swap_sx(a, cmds);
	rotate_rrx(a, cmds);
	swap_sx(a, cmds);
}

static void	sort_with_tail(t_stack *a, char **cmds)
{
	if (a->nbrs[2] < (a->nbrs)[1] && (a->nbrs)[1] < (a->nbrs)[0])
	{
		swap_sx(a, cmds);
		ra_sa_rra_sa(a, cmds);
	}
	else if (a->nbrs[2] < a->nbrs[0] && a->nbrs[0] < a->nbrs[1])
		ra_sa_rra_sa(a, cmds);
	else if (a->nbrs[1] < a->nbrs[2] && a->nbrs[2] < a->nbrs[0])
	{
		swap_sx(a, cmds);
		rotate_rx(a, cmds);
		swap_sx(a, cmds);
		rotate_rrx(a, cmds);
	}
	else if (a->nbrs[1] < a->nbrs[0] && a->nbrs[0] < a->nbrs[2])
		swap_sx(a, cmds);
	else if (a->nbrs[0] < a->nbrs[2] && a->nbrs[2] < a->nbrs[1])
	{
		rotate_rx(a, cmds);
		swap_sx(a, cmds);
		rotate_rrx(a, cmds);
	}
}

static void	sort_without_tail(t_stack *a, char **cmds)
{
	if (a->nbrs[2] < a->nbrs[1] && a->nbrs[1] < a->nbrs[0])
	{
		swap_sx(a, cmds);
		rotate_rrx(a, cmds);
	}
	else if (a->nbrs[2] < a->nbrs[0] && a->nbrs[0] < a->nbrs[1])
		rotate_rrx(a, cmds);
	else if (a->nbrs[1] < a->nbrs[2] && a->nbrs[2] < a->nbrs[0])
		rotate_rx(a, cmds);
	else if (a->nbrs[1] < a->nbrs[0] && a->nbrs[0] < a->nbrs[2])
		swap_sx(a, cmds);
	else if (a->nbrs[0] < a->nbrs[2] && a->nbrs[2] < a->nbrs[1])
	{
		rotate_rrx(a, cmds);
		swap_sx(a, cmds);
	}
}

void		sort_3a(t_stack *a, int n, char **cmds)
{
	if (n < 2)
		return ;
	if (n == 2)
	{
		if (a->nbrs[0] > a->nbrs[1])
			swap_sx(a, cmds);
		else
			return ;
	}
	if (a->nbrs[0] < a->nbrs[1] && a->nbrs[1] < a->nbrs[2])
		return ;
	if (n == 3 && a->nbrs_l == 3)
		sort_without_tail(a, cmds);
	else
		sort_with_tail(a, cmds);
}
