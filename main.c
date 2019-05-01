/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 19:46:28 by wtorwold          #+#    #+#             */
/*   Updated: 2018/12/24 18:54:02 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "fillit.h"


int main (int argc, char **ar)
{
	int fd;
	char *sqr;

	if (argc != 2)
	{
		printf("Error argc");
		return(-1);
	}
	fd = open(ar[1], O_RDONLY);
	if (fd == -1)
		printf("Error open.");
	sqr = ft_read(fd);
	if (sqr == NULL)
		printf("Error sqr.");
	else 
		 printf("sqr is ok");	
}

