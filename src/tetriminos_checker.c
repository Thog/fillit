/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:09 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/15 13:32:39 by tguillem         ###   ########.fr       */
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

char	***separe_shapes(char *file)
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
	ft_bzero(result, 27);
	while (*file && (*file == '#' || *file == '.' || *file == '\n'))
	{
		if (c > 4 || l > 4)
			return (NULL);
		if (*file == '\n')
		{
			l = 0;
			if (*(file + 1) == '\n' && (i = 1))
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
			*(*(*(result) + c) + l++) = *file;
		}
		file++;
	}
	return (*file ? NULL : origin);
}

char	*parse_shapes(char ***shapes)
{
	int		nb;
	int		i;
	int		j;
	int		k;
	int		chars;
	char	*parsed;

	nb = 0;
	i = 0;
	while (*(shapes + i))
	{
		nb++;
		char c = nb + '0';
		write(1, &c, 1);
		i++;
	}
	i = 0;
	if ((parsed = (char*)malloc(sizeof(char) * nb)) == NULL)
		return (NULL);
	write(1, "test", 4);
	while (i < nb)
	{
		chars = 0;
		j = 0;
		while (*(*(shapes + i) + j))
		{
			k = 0;
			while (*(*(*(shapes + i) + j) + k))
			{
				if (*(*(*(shapes + i) + j) + k) == '#')
					chars++;
				k++;
			}
			j++;
		}
		if (chars > 4)
		{
			write(1, "error\n", 5);
			return (NULL);
		}
		chars = 0;
		i++;
	}
	return (parsed);
}

char	*prepare_fill(char *fname)
{
	char	*filecontent;
	char	***shapes;

	filecontent = read_file(fname);
	if (!filecontent || !(shapes = separe_shapes(filecontent)))
		return (NULL);
	return (parse_shapes(shapes));
}
