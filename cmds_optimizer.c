/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_optimizer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 17:57:41 by vsosevic          #+#    #+#             */
/*   Updated: 2017/03/15 17:57:59 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	elif_help_ss(char **tmp, int *i, char **ret)
{
	tmp[*i + 1][0] = '\0';
	*ret = ft_strjoin_m(*ret, "ss\n");
}

static void	elif_help_rr(char **tmp, int *i, char **ret)
{
	tmp[*i + 1][0] = '\0';
	*ret = ft_strjoin_m(*ret, "rr\n");
}

static void	elif_help_rrr(char **tmp, int *i, char **ret)
{
	tmp[*i + 1][0] = '\0';
	*ret = ft_strjoin_m(*ret, "rrr\n");
}

static void	while_help(char **tmp, int *i, char **ret)
{
	if ((!ft_strcmp(tmp[*i], "sa") && !ft_strcmp(tmp[*i + 1], "sb")) ||
		(!ft_strcmp(tmp[*i], "sb") && !ft_strcmp(tmp[*i + 1], "sa")))
		elif_help_ss(tmp, i, ret);
	else if ((!ft_strcmp(tmp[*i], "ra") && !ft_strcmp(tmp[*i + 1], "rb")) ||
				(!ft_strcmp(tmp[*i], "rb") && !ft_strcmp(tmp[*i + 1], "ra")))
		elif_help_rr(tmp, i, ret);
	else if ((!ft_strcmp(tmp[*i], "rra") && !ft_strcmp(tmp[*i + 1], "rrb")) ||
				(!ft_strcmp(tmp[*i], "rrb") && !ft_strcmp(tmp[*i + 1], "rra")))
		elif_help_rrr(tmp, i, ret);
	else if ((!ft_strcmp(tmp[*i], "pa") && !ft_strcmp(tmp[*i + 1], "pb")) ||
				(!ft_strcmp(tmp[*i], "pb") && !ft_strcmp(tmp[*i + 1], "pa")) ||
				(!ft_strcmp(tmp[*i], "ra") && !ft_strcmp(tmp[*i + 1], "rra")) ||
				(!ft_strcmp(tmp[*i], "rb") && !ft_strcmp(tmp[*i + 1], "rrb")) ||
				(!ft_strcmp(tmp[*i], "rra") && !ft_strcmp(tmp[*i + 1], "ra")) ||
				(!ft_strcmp(tmp[*i], "rrb") && !ft_strcmp(tmp[*i + 1], "rb")))
	{
		tmp[*i][0] = '\0';
		tmp[*i + 1][0] = '\0';
		(*i)++;
	}
	else if (tmp[*i][0] != '\0')
	{
		*ret = ft_strjoin_m(*ret, tmp[*i]);
		*ret = ft_strjoin_m(*ret, "\n");
	}
}

void		cmds_optimizer(char **str)
{
	char	**tmp;
	char	*ret;
	int		i;

	tmp = ft_strsplit(*str, '\n');
	ret = (char *)malloc(sizeof(char));
	i = 0;
	while (tmp[i + 1])
	{
		while_help(tmp, &i, &ret);
		i++;
	}
	ret = ft_strjoin_m(ret, tmp[i]);
	ret = ft_strjoin_m(ret, "\n");
	free(*str);
	i = 0;
	while (tmp[i])
		free(tmp[i++]);
	free(tmp);
	*str = ret;
}
