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

void	ft_size(char *buf, int *code)
{
	int	i;
	code[0] = 0;
	code[1] = 0;
	code[2] = 5;
	code[3] = 5;
	i = 0;
	while (buf[i] != '\0')
	{
			if (buf[i] == '#')
		{
			if ((i % 5) > code[0])
				code[0] = (i % 5);
			if ((i / 5) > code[1])
				code[1] = (i / 5);
			if ((i % 5) < code[2])
				code[2] = (i % 5);
			if ((i / 5) < code[3])
				code[3] = (i / 5);
			}
		i++;
	}
}

void	ft_characteristic(char **blockcode, char *buf, int *code, char c)
{	
	int i;
	int hash;

	hash = 0;
	i = code[3]*5 + code[2];
	while(hash != 4)
	{
		if(buf[i] == '#')
		{
			*blockcode[0] = c;
			hash++;
		}
		i++;		
	}
	printf("hash = %d\n", hash);	
}

t_tetri	*ft_tetcode(char *buf, char c)
{
	t_tetri *block;
	int	code[6];
	char	*blockcode;
	int i;

	i = 0;
	if ((block = (t_tetri *)malloc(sizeof(t_tetri))) == NULL)
		return (NULL);
	if ((blockcode = ft_memalloc(14)) == NULL)
		return(NULL);
	ft_size(buf, code);
	code[4] = 1 + code[0] - code[2];
	code[5] = 1 + code[1] - code[3];
	block->x = code[4];
	block->y = code[5];
	block->tetris = codeblock(blockcode, buf, c, code);
	printf("%s %ld\n", block->tetris, ft_strlen(blockcode));
	printf("x = %d\n", block->x); 
	while(i < 6)
             printf("code = %d\n", code[i++]);
	return(block);
}


void	ft_createlist(t_list **sqr, char *buf, t_list **p) 
{
	t_tetri *block;
	static char c = 'A';

	if(*sqr == NULL)
{
	block = ft_tetcode(buf, c);
	if (block == NULL)
		return;
	*sqr = ft_lstnew(block, sizeof(t_tetri));
	if (*sqr == NULL)
	{
		ft_lstdel(sqr, ft_freetetri);
		return;
	}
	*p = *sqr;
	printf("------------------------\n");
}
	else 
{
	block = ft_tetcode(buf, c);
	if (block == NULL) 
	{
		ft_lstdel(sqr, ft_freetetri);
		return ;
	}
	(*p)->next = ft_lstnew(block, sizeof(t_tetri));
	if((*p)->next ==NULL)
		{
			ft_lstdel(sqr, ft_freetetri);
			return;
		}
	*p = (*p)->next;
	printf("------------------------\n");   
}
	c = c + 1;
}
