/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_from_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 21:44:03 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/20 21:44:17 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	mediana(t_stack *stk, int l)
{
	int i;
	int *tmp;
	int ret;

	tmp = (int *)malloc(sizeof(int) * l);
	i = -1;
	while (++i < l)
		tmp[i] = stk->nbrs[i];
	bubble_sort(tmp, l);
	if (l % 2 == 1)
		ret = tmp[l / 2];
	else
	{
		if (stk->name == 'a')
			ret = tmp[l / 2];
		else
			ret = tmp[l / 2 - 1];
	}
	free(tmp);
	return (ret);
}

int			to_be_pushed(t_stack *stk, int med)
{
	int ret;
	int i;

	ret = 0;
	i = 0;
	if (stk->name == 'a')
	{
		while (i < stk->nbrs_l)
		{
			if (stk->nbrs[i] < med)
				ret++;
			i++;
		}
	}
	else
	{
		while (i < stk->nbrs_l)
		{
			if (stk->nbrs[i] > med)
				ret++;
			i++;
		}
	}
	return (ret);
}

static int	if_stk_is_a(t_stack *from, t_stack *to, char **cmds, int med)
{
	int pushed;
	int rot_back;

	rot_back = 0;
	pushed = to_be_pushed(from, med);
	while (pushed > 0)
	{
		if (from->nbrs[0] < med)
		{
			push_b(from, to, cmds);
			pushed--;
		}
		else
		{
			rotate_rx(from, cmds);
			rot_back++;
		}
	}
	return (rot_back);
}

static int	if_stk_is_b(t_stack *from, t_stack *to, char **cmds, int med)
{
	int pushed;
	int rot_back;

	rot_back = 0;
	pushed = to_be_pushed(from, med);
	while (pushed > 0)
	{
		if (from->nbrs[0] > med)
		{
			push_a(to, from, cmds);
			pushed--;
		}
		else
		{
			rotate_rx(from, cmds);
			rot_back++;
		}
	}
	return (rot_back);
}

int			med_push_from_to(t_stack *from, t_stack *to, int n, char **cmds)
{
	int rot_back;
	int med;
	int pushed;
	int stk_size;
	int ret;

	stk_size = from->nbrs_l;
	med = mediana(from, n);
	pushed = to_be_pushed(from, med);
	ret = pushed;
	rot_back = 0;
	if (from->name == 'a')
		rot_back = if_stk_is_a(from, to, cmds, med);
	else
		rot_back = if_stk_is_b(from, to, cmds, med);
	if (stk_size != n)
		while (rot_back > 0)
		{
			rotate_rrx(from, cmds);
			rot_back--;
		}
	return (ret);
}
