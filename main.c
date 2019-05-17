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

/*void    ft_freetetri(void *block, size_t size)
{
        printf("%d\n", (int)size);  
	if(block != NULL)
          {
                printf("block->tetris is valid\n");
                free(((t_tetri *)block)->tetris);
                free(block);
                block = NULL;
	//	if(((t_tetri *)block)->tetris != NULL) 
	//	printf("%s\n", ((t_tetri *)block)->tetris);
	//	printf("%d\n", (int)size);
          }
}*/


int main (int argc, char **ar)
{
	int fd;
	t_list *sqr;
	t_tetri *test;

	if (argc != 2)
	{
		printf("Error argc");
		return(-1);
	}
	fd = open(ar[1], O_RDONLY);
	if (fd == -1)
		printf("Error opening");
	sqr = ft_read(fd);
        if (sqr == NULL)
	{
                printf("Error sqr\n");
		return(1);
	}
        else
                printf("sqr is ok\n");	
	while (sqr)
	{
		test = sqr->content;
		printf("main = %s\n", (char *)test->tetris);
		sqr= sqr->next;
	}
	if (close(fd) == -1)
	{
		printf("Error closing\n");
		return(1);
	}	
}

