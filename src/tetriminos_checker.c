/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:09 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/16 15:25:25 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**alloc_piece(void)
{
	int		n;
	char	**result;

	n = 4;
	result = (char **)malloc(sizeof(char*) * 4);
	if (!result)
		return (NULL);
	while (n--)
	{
		result[n] = (char*)malloc(sizeof(char) * 5);
		ft_bzero(result[n], 5);
	}
	return (result);
}

int		separe_shapes(char *file, char ****shapes)
{
	char	***result;
	char	***origin;
	int		c;
	int		l;
	int		i;

	c = 0;
	l = 0;
	i = 0;
	result = *shapes;
	origin = result--;
	while (*file && (*file == '#' || *file == '.' || *file == '\n')
			&& ((c <= 4 || l <= 4) || (*(result + 1) = NULL)))
	{
		if (*file == '\n' && (l = 0) + 1)
		{
			if (*(file + 1) == '\n' && (i = 1))
				c = 0;
			else if (!i || (i = 0 && 0))
				c++;
		}
		else
		{
			if (!l && !c)
				*(++result) = alloc_piece();
			*(*(*(result) + c) + l++) = *file;
		}
		file++;
	}
	*shapes = origin;
	return (*file ? 0 : 1);
}

char	*prepare_fill(char *fname)
{
	char	*fcontent;
	char	***shapes;
	int		i;

	fcontent = read_file(fname);
	if (!fcontent || !(shapes = (char ***)ft_memalloc(sizeof(char**) * 28)) ||
			!separe_shapes(fcontent, &shapes))
		return (NULL);
	i = 0;
	while (*(shapes + i) != NULL && i < 27)
		i++;
	printf("%d\n", i);
	return (NULL);
}
