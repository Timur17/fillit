/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:46:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/05/29 23:05:52 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void				ft_write(t_list *sqr, int x, int y)
{
	char		*tetris;
	int			i;

	i = 0;
	tetris = ((t_tetri *)sqr->content)->tetris;
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
			g_board[y][x] = tetris[i];
		else if (tetris[i] == 'r')
			x++;
		else if (tetris[i] == 'd')
			y++;
		else if (tetris[i] == 'l')
			x--;
		i++;
	}
}

static int				ft_check(t_list *sqr, int x, int y)
{
	char		*tetris;
	int			i;

	i = 0;
	tetris = ((t_tetri *)sqr->content)->tetris;
	if ((x + ((t_tetri*)(sqr->content))->x) > g_size ||
		(y + ((t_tetri*)(sqr->content))->y) > g_size)
		return (0);
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
		{
			if (g_board[y][x] != '.')
				return (0);
		}
		else if (tetris[i] == 'r')
			x++;
		else if (tetris[i] == 'd')
			y++;
		else if (tetris[i] == 'l')
			x--;
		i++;
	}
	return (1);
}

void					ft_clean(t_list *sqr)
{
	char		*tetris;
	char		tetris_char;
	int			i;

	i = 0;
	tetris = ((t_tetri *)sqr->content)->tetris;
	while (tetris[i] != '\0')
	{
		if (tetris[i] >= 'A' && tetris[i] <= 'Z')
			tetris_char = tetris[i];
		i++;
	}
	i = 0;
	while (i < g_size)
		ft_strreplace(g_board[i++], tetris_char, '.');
}

static int				solution(t_list *sqr, int x, int y)
{
	if (sqr == NULL)
		return (1);
	while (g_size >= y + ((t_tetri*)(sqr->content))->y)
	{
		x = 0;
		while (g_size >= x + ((t_tetri*)(sqr->content))->x)
		{
			if (ft_check(sqr, x, y) == 1)
			{
				ft_write(sqr, x, y);
				if (solution(sqr->next, 0, 0) == 1)
					return (1);
				else
					ft_clean(sqr);
			}
			x++;
		}
		y++;
	}
	return (-1);
}

void					ft_bt(t_list *sqr)
{
	g_size = ft_sqrt(ft_listlen(sqr) * 4);
	ft_board();
	while ((solution(sqr, 0, 0)) != 1)
	{
		g_size++;
		ft_board();
	}
	ft_printboard();
}
