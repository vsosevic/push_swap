/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsosevic <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:02:30 by vsosevic          #+#    #+#             */
/*   Updated: 2016/12/01 15:20:44 by vsosevic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	has_alpha(const char *str, int i)
{
	while (str[i] != '\0')
		if (!ft_isdigit(str[i++]))
			ft_exit("\x1B[31mError\n\x1B[33mNot a number in the list\n");
}

int			ft_atoi_modified(const char *str)
{
	int				i;
	long long int	n;
	int				flag;

	i = 0;
	n = 0;
	flag = 1;
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	if (str[i] == '-' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
	{
		flag = -1;
		i++;
	}
	has_alpha(str, i);
	while (str[i] >= '0' && str[i] <= '9')
		n = n * 10 + (str[i++] - '0');
	if (n < -2147483648 || n > 217483647)
		ft_exit("\x1B[31mError\n\x1B[33mOut of int range\n");
	return (n * flag);
}
