/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:09 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/07 09:41:50 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
		result[n][4] = '\0';
	}
	return (result);
}

char	***separe_shapes(char *fcontent)
{
	char	***result;
	char	***origin;
	int		c;
	int		l;
	int		i;

	c = 0;
	l = 0;
	i = 0;
	result = (char ***)malloc(sizeof(char**) * 27);
	origin = result--;
	if (!result)
		return (NULL);
	while (*fcontent)
	{
		if (c > 4 || l > 4)
			return (NULL);
		if (*fcontent == '\n')
		{
			l = 0;
			if (*(fcontent + 1) == '\n' && (i = 1))
				c = 0;
			else if (!i)
				c++;
			else
				i = 0;
		}
		else
		{
			if (!l && !c)
				*(++result) = alloc_piece();
			*(*(*(result) + c) + l++) = *fcontent;
		}
		fcontent++;
	}
	return (origin);
}

char	**prepare_fill(char *fname)
{
	char	*filecontent;
	char	***pieces;

	filecontent = read_file(fname);
	if (!filecontent)
	{
		return (NULL);
	}
	pieces = separe_shapes(filecontent);
	return (pieces[1]);
}
