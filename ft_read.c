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
#include <string.h>

int	ft_check_first(char *tetr, int ret)
{
	int i = 10%5;
	printf(" %d\n", i);
	if (ret !=20 && ret != 21)
		return (0);
	if (tetr[20] != '\n' && tetr[20] != '\0')
		return (0);
	return(1);
}	

char *ft_read (int fd)
{
	int ret;
	int BUF_SIZE = 21;
	char buf[BUF_SIZE + 1];
	char *sqr = NULL;
	
	if((ret = read(fd, buf, BUF_SIZE)) > 0 )
	{
		buf[ret] = '\0';
		printf("%s %d\n", buf, ret);
		if (ft_check_first(buf, ret) == 0)
			return (sqr);
	}
	if (ret == -1)
		return (sqr);
	sqr = (char *)malloc(sizeof(char) * (ret + 1));
	memcpy(sqr, buf, ret);
	return(sqr);

}

