/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 12:44:43 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/09 12:45:37 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *a, t_stack *b, char **cmds)
{
	if (a->nbrs_l > 0)
	{
		shift_down(b);
		b->nbrs[0] = a->nbrs[0];
		shift_up(a);
		(*cmds) = ft_strjoin_m(*cmds, "pb\n");
	}
}

void	rotate_rx(t_stack *stk, char **cmds)
{
	int tmp;

	if (stk->nbrs_l > 1)
	{
		tmp = stk->nbrs[0];
		shift_up(stk);
		stk->nbrs[stk->nbrs_l++] = tmp;
		if (stk->name == 'a')
			(*cmds) = ft_strjoin_m(*cmds, "ra\n");
		else
			(*cmds) = ft_strjoin_m(*cmds, "rb\n");
	}
}

void	rotate_rr(t_stack *a, t_stack *b, char **cmds)
{
	rotate_rx(a, cmds);
	rotate_rx(b, cmds);
}

void	rotate_rrx(t_stack *stk, char **cmds)
{
	int tmp;

	if (stk->nbrs_l > 1)
	{
		tmp = stk->nbrs[stk->nbrs_l - 1];
		shift_down(stk);
		stk->nbrs[0] = tmp;
		stk->nbrs_l--;
		if (stk->name == 'a')
			(*cmds) = ft_strjoin_m(*cmds, "rra\n");
		else
			(*cmds) = ft_strjoin_m(*cmds, "rrb\n");
	}
}

void	rotate_rrr(t_stack *a, t_stack *b, char **cmds)
{
	rotate_rrx(a, cmds);
	rotate_rrx(b, cmds);
}
