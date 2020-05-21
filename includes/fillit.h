/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wtorwold <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:19:31 by wtorwold          #+#    #+#             */
/*   Updated: 2019/05/29 22:59:07 by wtorwold         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLIT_H
# define FT_FILLIT_H
# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# define BUF_SIZE 21

char			g_board[30][30];
int				g_size;

typedef	struct	s_tetri
{
	int			x;
	int			y;
	char		*tetris;
}				t_tetri;

t_list			*ft_read(int fd);
void			ft_createlist(t_list **sqr, char *buf, t_list **p);
char			*codeblock(char *bc, char *buf, char c, int code[6]);
void			ft_freetetri(void *block, size_t size);
void			ft_bt(t_list *sqr);
void			ft_printboard(void);
void			ft_board(void);
int				ft_sqrt(int nb);
int				ft_listlen(t_list *sqr);
void			ft_strreplace(char *str, char old, char new);

#endif
