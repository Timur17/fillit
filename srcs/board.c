/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:46:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/05/29 23:05:06 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_strreplace(char *str, char old, char new)
{
	while (*str)
	{
		if (*str == old)
			*str = new;
		str++;
	}
}

void				ft_printboard(void)
{
	int			i;

	i = 0;
	while (g_size > i)
	{
		write(1, g_board[i++], g_size);
		write(1, "\n", 1);
	}
}

void				ft_board(void)
{
	int			i;
	int			j;

	i = 0;
	while (g_size > i)
	{
		j = 0;
		while (g_size > j)
		{
			g_board[i][j] = '.';
			j++;
		}
		g_board[i][j] = '\0';
		i++;
	}
}

int					ft_sqrt(int nb)
{
	int			i;

	i = 1;
	if (nb <= 0 || nb > 2147483647)
		return (0);
	else
	{
		while (i * i <= nb)
		{
			if (i * i == nb)
				return (i);
			if (i * i < nb && ((i + 1) * (i + 1) > nb))
				return (i + 1);
			else
				i++;
		}
		return (0);
	}
}

int					ft_listlen(t_list *sqr)
{
	int			count;
	t_list		*p;

	p = sqr;
	count = 0;
	while (p)
	{
		count++;
		p = p->next;
	}
	return (count);
}
