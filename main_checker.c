/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 15:00:27 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/23 15:01:57 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	apply_cmds(t_stack *a, t_stack *b, char *line, char **cmds)
{
	if (ft_strcmp(line, "sa") == 0)
		swap_sx(a, cmds);
	else if (ft_strcmp(line, "sb") == 0)
		swap_sx(b, cmds);
	else if (ft_strcmp(line, "ss") == 0)
		swap_ss(a, b, cmds);
	else if (ft_strcmp(line, "pa") == 0)
		push_a(a, b, cmds);
	else if (ft_strcmp(line, "pb") == 0)
		push_b(a, b, cmds);
	else if (ft_strcmp(line, "ra") == 0)
		rotate_rx(a, cmds);
	else if (ft_strcmp(line, "rb") == 0)
		rotate_rx(b, cmds);
	else if (ft_strcmp(line, "rr") == 0)
		rotate_rr(a, b, cmds);
	else if (ft_strcmp(line, "rra") == 0)
		rotate_rrx(a, cmds);
	else if (ft_strcmp(line, "rrb") == 0)
		rotate_rrx(b, cmds);
	else if (ft_strcmp(line, "rrr") == 0)
		rotate_rrr(a, b, cmds);
	else
		ft_exit("\x1B[31mError\n\x1B[33mWrong command in the list");
}

int			main(int argc, char **argv)
{
	int		*nbrs;
	t_stack	*a;
	t_stack	*b;
	char	*line;
	char	*cmds;

	if (argc == 1)
		ft_exit("Enter numbers like '3 1 2' and gimme valid commands to sort");
	nbrs = nbrs_from_argv(argv, argc - 1);
	a = (t_stack *)malloc(sizeof(t_stack));
	b = (t_stack *)malloc(sizeof(t_stack));
	create_stacks(nbrs, argc - 1, a, b);
	while (get_next_line(0, &line) > 0)
		apply_cmds(a, b, line, &cmds);
	if (stk_a_is_sorted(a, a->nbrs_l) && b->nbrs_l == 0)
		ft_exit("\x1B[32mOK\x1B[0m\n");
	else
		ft_exit("\x1B[31mKO\x1B[0m\n");
	return (0);
}
