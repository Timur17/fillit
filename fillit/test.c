#include "libft/libft.h"    
#include "fillit.h"

int			blockletter(char *blockcode, char *buf, char c, int xyjbm[5])
{
	if (buf[(xyjbm[0] + 5 * xyjbm[1])] == '.')
	{
		blockcode[xyjbm[2]] = '.';
		xyjbm[2]++;
		return (1);
	}
	else if (buf[(xyjbm[0] + 5 * xyjbm[1])] == '#')
	{
		blockcode[xyjbm[2]] = c;
		xyjbm[2]++;
		return (1);
	}
	return (-1);
}

void		checkright(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'r';
	xyjbm[0]++;
}

void		checkleft(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'l';
	xyjbm[0]--;
}

void		checkdown(char *blockcode, char *buf, char c, int xyjbm[5])
{
	xyjbm[3] += blockletter(blockcode, buf, c, xyjbm);
	blockcode[xyjbm[2]++] = 'd';
	xyjbm[1]++;
}

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
}

char	*codeblock(char *bc, char *buf, char c, int code[6])
{
	int		xyjbm[5];

	xyjbm[0] = code[2];
	xyjbm[1] = code[3];
	xyjbm[2] = 0;
	xyjbm[3] = 0;
	xyjbm[4] = code[4] * code[5];
	while (xyjbm[3] < (xyjbm[4] - 1))
	{
		while (xyjbm[0] < code[0] && xyjbm[3] < (xyjbm[4] - 1))
			checkright(bc, buf, c, xyjbm);
		if (xyjbm[1] < code[1] && xyjbm[3] < (xyjbm[4] - 1))
			checkdown(bc, buf, c, xyjbm);
		while (xyjbm[0] > code[2] && xyjbm[3] < (xyjbm[4] - 1))
			checkleft(bc, buf, c, xyjbm);
		if (xyjbm[1] < code[1] && xyjbm[3] < (xyjbm[4] - 1))
			checkdown(bc, buf, c, xyjbm);
	}
	blockletter(bc, buf, c, xyjbm);
	return (bc);
}

