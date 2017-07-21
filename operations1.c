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

void	shift_down(t_stack *stk)
{
	int i;

	i = stk->nbrs_l;
	while (i > 0)
	{
		stk->nbrs[i] = stk->nbrs[i - 1];
		i--;
	}
	stk->nbrs_l++;
}

void	shift_up(t_stack *stk)
{
	int i;

	i = 0;
	while (i < stk->nbrs_l - 1)
	{
		stk->nbrs[i] = stk->nbrs[i + 1];
		i++;
	}
	stk->nbrs_l--;
}

void	swap_sx(t_stack *stk, char **cmds)
{
	if (stk->nbrs_l > 1)
	{
		ft_swap_int(&stk->nbrs[0], &stk->nbrs[1]);
		if (stk->name == 'a')
			(*cmds) = ft_strjoin_m(*cmds, "sa\n");
		else
			(*cmds) = ft_strjoin_m(*cmds, "sb\n");
	}
}

void	swap_ss(t_stack *a, t_stack *b, char **cmds)
{
	swap_sx(a, cmds);
	swap_sx(b, cmds);
}

void	push_a(t_stack *a, t_stack *b, char **cmds)
{
	if (b->nbrs_l > 0)
	{
		shift_down(a);
		a->nbrs[0] = b->nbrs[0];
		shift_up(b);
		(*cmds) = ft_strjoin_m(*cmds, "pa\n");
	}
}
