/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:46:28 by wtorwold          #+#    #+#             */
/*   Updated: 2019/05/01 20:35:10 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"

//char line[100][100];

char **ft_board(int size)
{
	char **line;
	int i;

	i = 0;
	line = (char **)malloc(sizeof(line) * size);
	if (line == NULL)
		return(NULL);
	while (size > i)
	{
		line[i] = ft_memalloc(size + 1);
		if (line[i] == NULL)
			return(NULL);
		line[i] = ft_memset(line[i], '.', size);
		i++;
	}
	return (line);
}	
/*char **ft_board(int size, char **line)
{
	int i;
	int j;
//	char *p;
	
	i = 0;
	 while (size > i)
	{
		j = 0;
		while (size > j)
		{
			line[i][j] = '.';
			j++;
		}
		line[i][j] = '\0';
		i++;
	}	
	return (line);
}*/

int	ft_sqrt(int nb)
{
	int i;

	i = 1;
	if(nb <= 0 || nb > 2147483647)
		return(0);
	else
	{
		while(i * i <= nb)
			{
				if(i * i == nb)
					return(i);
				if(i * i < nb && ((i + 1) * (i + 1) > nb))
					return(i + 1);
				else
					i++;
			}
		return(0);
	}
}

int	ft_listlen(t_list *sqr)
{
	int count;
	t_list *p;
	p = sqr;

	count = 0;
	
	while(p)
	{	
		count++;
		p = p->next;
	}
	return (count);
}

char	 **ft_write(t_list *sqr, char **board, int x, int y)
{
	char *tetris;
	int i;
	
	i = 0;
	tetris = ((t_tetri *)sqr->content)->tetris;
//	printf("%s\n", tetris);
	while(tetris[i] != '\0')
	{
		if(tetris[i] == '.')
			i++;
		if(tetris[i] == 'r')
			x++;
		if(tetris[i] == 'd')
			y++;
		if(tetris[i] == 'l')
			x--;
		if(tetris[i] >= 'A' && tetris[i] <= 'Z')
			board[y][x] = tetris[i];
		i++;
			
			
	}
	return (board);
}

int     ft_check(t_list *sqr, char **board, int x, int y)
{
	char *tetris;
	int i;
	
	i = 0;
	
	tetris = ((t_tetri *)sqr->content)->tetris;
	while(tetris[i] != '\0')
	{
		if(tetris[i] == '.')
			i++;
		if(tetris[i] == 'r')
			x++;
		if(tetris[i] == 'd')
			y++;
		if(tetris[i] == 'l')
			x--;
		if(board[y][x] == '.')
			i++;
		else
			return(0); 
	}
	return(1);

}

int	 solution(t_list *sqr, char **board, int x, int y)
{
	int	h;
	int	w;
	int	f;
	
	f = 0;
	w = (int)ft_strlen(board[0]);
	h = w;
	if (((int)ft_strlen(board[0]) < ((t_tetri*)(sqr->content))->y))
		return(-1);
	if (((int)ft_strlen(board[0]) < ((t_tetri*)(sqr->content))->x))
		return(-1);
	while (h > y)
//	if (( h < y + ((t_tetri*)(sqr->content))->y))
//		solution(sqr->next, board, 0, 0);;
	{
	x = 0;
	while(w > x)
	{
		
		if (ft_check(sqr, board, x, y) == 1)
			{	
				if ((board = ft_write(sqr, board, x, y)) == 0)
					return(-1);
				f++;
				printf("SOLUTION WAS FOUND\n");
				break ;
			}	
		x++;
	}
	if (f > 0)
		break ;
	y++;
	}
	if (f == 0)
		return(-1);
//	if (sqr->next != NULL)
//		solution(sqr->next, board, 0, 0);
	return(0);
}

void	ft_bt(t_list *sqr)
{
	t_tetri *pp;
	t_list *p;
	int size;
	char **board;
	 printf("DESCRIPTION OF TETROMINOS\n");
	p = sqr;
	while(p)
	{
		pp = p->content;
		printf("%s\n", pp->tetris);
		p=p->next;
	}
	printf("__________________________\n");
	size = ft_listlen(sqr);
	size = ft_sqrt(size * 4);
	printf("size of board = %d\n", size);
	board = ft_board(size);
	printf("RESULT OF FT_BOARD\n");
	int i = 0;
	while(size > i)
	{
		printf("%s\n", board[i]);	
		i++;
	}
	printf("__________________________\n");
	
	printf("RESULT OF SOLUTION\n");
	while ((solution(sqr, board, 0, 0)) == -1)
	{
		
		board = ft_board(size + 1);
	}
	size = ft_strlen(board[0]);
	i = 0;
	while(size > i)
	{
		printf("%s\n", board[i]);
		i++;
	}
/*	printf("RESULT OF FT_WRITE\n");
	board = ft_write(sqr, board, 0, 0);
	i = 0;
	while(size > i)
	{
		printf("%s\n", board[i]);
		i++;
	}
	printf("__________________________\n");
	if (ft_check(sqr, board, 0, 0) == 1)
		printf("OK");
	else
		printf("BAD"); */

}
