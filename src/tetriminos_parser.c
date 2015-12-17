/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-baz <bel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:22:58 by bel-baz           #+#    #+#             */
/*   Updated: 2015/12/17 16:30:25 by bel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pieces.h"

static char	get_crown(char **shape, int i, int j)
{
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i + 1) + j - 1) == '#')
		return (CROWN_UP);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i + 2) + j) == '#')
		return (CROWN_RIGHT);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
				1) == '#' && *(*(shape + i + 2) + j) == '#')
		return (CROWN_LEFT);
	if (i < 2 && *(*(shape + i) + j + 1) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i + 2) + j) == '#')
		return (CROWN_DOWN);
	return (UNKNOWN);
}

static char	get_l(char **shape, int i, int j)
{
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i + 1) + j + 2) == '#')
		return (L_LEFT_UP);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i) + j +
				1) == '#' && *(*(shape + i + 2) + j) == '#')
		return (L_LEFT_RIGHT);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 2) + j -
				1) == '#' && *(*(shape + i + 2) + j) == '#')
		return (L_LEFT_LEFT);
	if (i < 2 && *(*(shape + i + 1) + j + 2) == '#' && *(*(shape + i) + j +
				1) == '#' && *(*(shape + i) + j + 2) == '#')
		return (L_LEFT_DOWN);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
				1) == '#' && *(*(shape + i + 1) + j - 2) == '#')
		return (L_RIGHT_UP);
	if (i < 2 && *(*(shape + i) + j + 1) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i + 2) + j + 1) == '#')
		return (L_RIGHT_LEFT);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 2) + j)
			== '#' && *(*(shape + i + 2) + j + 1) == '#')
		return (L_RIGHT_RIGHT);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i) + j +
				1) == '#' && *(*(shape + i) + j + 2) == '#')
		return (L_RIGHT_DOWN);
	return (UNKNOWN);
}

static char	get_misc(char **shape, int i, int j)
{
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
				1) == '#' && *(*(shape + i) + j + 1) == '#')
		return (STAIRS_RIGHT_HOR);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i + 2) + j + 1) == '#')
		return (STAIRS_RIGHT_VER);
	if (i < 2 && *(*(shape + i) + j + 1) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i + 1) + j + 2) == '#')
		return (STAIRS_LEFT_HOR);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
				1) == '#' && *(*(shape + i + 2) + j - 1) == '#')
		return (STAIRS_LEFT_VER);
	if (*(*(shape + i) + j + 1) == '#' && *(*(shape + i) + j +
				2) == '#' && *(*(shape + i) + j + 3) == '#')
		return (BAR_HOR);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 2) + j)
			== '#' && *(*(shape + i + 3) + j) == '#')
		return (BAR_VER);
	if (i < 2 && *(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
				1) == '#' && *(*(shape + i) + j + 1) == '#')
		return (SQUARE);
	return (UNKNOWN);
}

char		get_piece(char **shape)
{
	char	rtn;
	int		i;
	int		j;

	i = -1;
	while (*(shape + ++i))
	{
		j = -1;
		while (*(*(shape + i) + ++j))
		{
			if (*(*(shape + i) + j) == '#')
			{
				if (!(rtn = get_crown(shape, i, j)))
				{
					if (!(rtn = get_l(shape, i, j)))
					{
						if (!(rtn = get_misc(shape, i, j)))
							return (UNKNOWN);
					}
				}
				return (rtn);
			}
		}
	}
	return (UNKNOWN);
}
