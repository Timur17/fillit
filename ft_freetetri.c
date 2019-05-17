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

#include "fillit.h"

void    ft_freetetri(void *block, size_t size)
{
        printf("%d\n", (int)size);  
	if(block != NULL)
          {
                printf("block->tetris is valid\n");
                free(((t_tetri *)block)->tetris);
                free(block);
                block = NULL;
          }
}
