/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/17 16:41:18 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/17 16:41:33 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		stk_a_is_sorted(t_stack *a, int n)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (i < a->nbrs_l - 1 && i < n - 1)
	{
		if (a->nbrs[i] > a->nbrs[i + 1])
			return (0);
		i++;
	}
	return (res);
}

int		stk_b_is_sorted(t_stack *b, int n)
{
	int i;
	int res;

	i = 0;
	res = 1;
	while (i < b->nbrs_l - 1 && i < n - 1)
	{
		if (b->nbrs[i] < b->nbrs[i + 1])
			return (0);
		i++;
	}
	return (res);
}

int		*nbrs_from_argv(char **argv, int n)
{
	int i;
	int j;
	int *nbrs;

	i = 0;
	nbrs = (int *)malloc(sizeof(int) * n);
	while (i < n)
	{
		nbrs[i] = ft_atoi_modified(argv[i + 1]);
		j = i;
		while (j > 0)
			if (nbrs[--j] == nbrs[i])
				ft_exit("\x1B[31mError\n\x1B[33mDuplicates in the list");
		i++;
	}
	return (nbrs);
}

void	create_stacks(int *nbrs, int nbrs_len, t_stack *a, t_stack *b)
{
	int i;

	a->nbrs = (int *)malloc(sizeof(int) * nbrs_len);
	a->nbrs_l = nbrs_len;
	a->name = 'a';
	i = 0;
	while (i < nbrs_len)
	{
		a->nbrs[i] = nbrs[i];
		i++;
	}
	b->nbrs = (int *)malloc(sizeof(int) * nbrs_len);
	b->nbrs_l = 0;
	b->name = 'b';
}
/*
**void	print_stacks(t_stack *a, t_stack *b, int argc)
**{
**	int i;
**	int n;
**
**	i = 0;
**	printf("_____________________\n");
**	printf("| Stack A | Stack B |\n");
**	printf("---------------------\n");
**	while (i < argc - 1)
**	{
**		if (i < a->nbrs_l)
**			printf("| %4d    |", a->nbrs[i]);
**		else
**			printf("|%9s|", " ");
**		if (i < b->nbrs_l)
**			printf(" %4d    |", b->nbrs[i]);
**		else
**			printf("%9s|", " ");
**		printf("\n");
**		i++;
**	}
**}
*/
