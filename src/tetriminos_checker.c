/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:09 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/03 12:09:59 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**alloc_piece()
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

char	**compute_file(char *fcontent)
{
	char	**result;
	int		c;
	int		l;

	c = 0;
	l = 0;
	result = alloc_piece();
	if (!result)
		return (NULL);
	while(*fcontent)
	{
		if (*fcontent == '\n')
		{
			l = 0;
			c++;
			if (*(fcontent + 1) == '\n')
				c = 0;
			printf("%d\n", c);
		} else
		{
			result[c][l] = *fcontent;
			printf("result[%d][%d] = %c;\n", c, l, *fcontent);
			l++;
		}
		fcontent++;
	}
	return (result);
}

char	**prepare_fill(char *fname)
{
	char	*filecontent;

	filecontent = read_file(fname);
	if (!filecontent)
	{
		return (NULL);
	}
	return (compute_file(filecontent));
}
