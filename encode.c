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
#include <stdio.h>
# include <fcntl.h>

static void	checkpos(char *tetri, int code[6])
{
	int		i;

	i = 0;
	code[0] = 0;
	code[1] = 0;
	code[2] = 5;
	code[3] = 5;
	while (tetri[i])
	{
		if (tetri[i] == '#')
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
	i = 0;
	while(i < 4)
		printf("%d", code[i++]);
}


int main (int argc, char **ar)
{
	int fd;
	char sqr[21];
	int code[6];
	int ret;
	

	if (argc != 2)
	{
		printf("Error argc");
		return(-1);
	}
	fd = open(ar[1], O_RDONLY);
	if (fd == -1)
		printf("Error open.");
	ret = read(fd, sqr, 21);
	sqr[ret] = '\0';
	printf("%s\n", sqr);
	checkpos(sqr, code); 
/*	sqr = ft_read(fd);
	if (sqr == NULL)
		printf("Error sqr.");
	else 
		 printf("sqr is ok");	*/
}

