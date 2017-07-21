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

void	ft_optimizer(char **cmds)
{
	cmds_optimizer(cmds);
	cmds_optimizer(cmds);
	cmds_optimizer(cmds);
	cmds_optimizer(cmds);
	cmds_optimizer(cmds);
}

int		main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	int		*nbrs;
	char	*cmds;

	cmds = (char *)malloc(sizeof(char) * 1);
	nbrs = nbrs_from_argv(argv, argc - 1);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	create_stacks(nbrs, argc - 1, a, b);
	if (stk_a_is_sorted(a, a->nbrs_l) && b->nbrs_l == 0)
		ft_exit("");
	if (stk_b_is_sorted(a, a->nbrs_l) == 1 && argc > 11)
		stk_bubble_sort(a, b, &cmds);
	else
		quicksort_a(a, b, argc - 1, &cmds);
	ft_optimizer(&cmds);
	ft_putstr(cmds);
	free(a->nbrs);
	free(b->nbrs);
	free(a);
	free(b);
	free(nbrs);
	free(cmds);
	return (0);
}
