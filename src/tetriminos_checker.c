/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:09 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/17 11:51:19 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_piece		*alloc_piece(char letter, int id)
{
	t_piece		*result;

	if (!(result = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	result->id = id;
	result->letter = letter;
	return (result);
}

static char			**alloc_rawpiece(void)
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

static int			separe_shapes(char *file, char ****shapes)
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
				*(++result) = alloc_rawpiece();
			*(*(*(result) + c) + l++) = *file;
		}
		file++;
	}
	*shapes = origin;
	return (*file ? 0 : 1);
}

static void			piece_add(t_piece **piece, t_piece *node)
{
	if (*piece)
		(*piece)->next = node;
	else
		*piece = node;
}

t_piece				*prepare_fill(char *fname)
{
	char		*fcontent;
	char		***shapes;
	t_piece		*data[3];
	int			i;

	fcontent = read_file(fname);
	if (!fcontent || !(shapes = (char ***)ft_memalloc(sizeof(char**) * 28)) ||
			!separe_shapes(fcontent, &shapes) ||
			(!(data[2] = alloc_piece('\0', UNKNOWN))))
		return (NULL);
	i = 0;
	while (*(shapes + i) != NULL && i < 27)
	{
		if (!(data[1] = alloc_piece('A' + i, get_piece(*(shapes + i)))))
			return (NULL);
		if (!i)
			data[0] = data[1];
		piece_add((data + 2), data[1]);
		data[2] = data[1];
		i++;
	}
	free(fcontent);
	free(shapes);
	return (data[0]);
}
