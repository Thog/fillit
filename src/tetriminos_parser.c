/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_parser.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-baz <bel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:22:58 by bel-baz           #+#    #+#             */
/*   Updated: 2015/12/15 15:51:52 by bel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pieces.h"

char	get_piece(char **shape)
{
	int i;
	int j;

	i = 0;
	while (*(shape + i))
	{
		j = 0;
		while (*(*(shape + i) + j))
		{
			if (*(*(shape + i) + j) == '#')
			{
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i + 1) + j - 1) == '#')
					return (CROWN_UP);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i + 2) + j) == '#')
					return (CROWN_RIGHT);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
							1) == '#' && *(*(shape + i + 2) + j) == '#')
					return (CROWN_LEFT);
				if (*(*(shape + i) + j + 1) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i + 2) + j) == '#')
					return (CROWN_DOWN);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i) + j + 1) == '#')
					return (SQUARE);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i + 1) + j + 2) == '#')
					return (L_LEFT_UP);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i) + j +
							1) == '#' && *(*(shape + i + 2) + j) == '#')
					return (L_LEFT_RIGHT);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 2) + j -
							1) == '#' && *(*(shape + i + 2) + j) == '#')
					return (L_LEFT_LEFT);
				if (*(*(shape + i + 1) + j + 2) == '#' && *(*(shape + i) + j +
							1) == '#' && *(*(shape + i) + j + 2) == '#')
					return (L_LEFT_DOWN);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
							1) == '#' && *(*(shape + i + 1) + j - 2) == '#')
					return (L_RIGHT_UP);
				if (*(*(shape + i) + j + 1) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i + 2) + j + 1) == '#')
					return (L_RIGHT_LEFT);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 2) + j)
						== '#' && *(*(shape + i + 2) + j + 1) == '#')
					return (L_RIGHT_RIGHT);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i) + j +
							1) == '#' && *(*(shape + i) + j + 2) == '#')
					return (L_RIGHT_DOWN);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
							1) == '#' && *(*(shape + i) + j + 1) == '#')
					return (STAIRS_RIGHT_HOR);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i + 2) + j + 1) == '#')
					return (STAIRS_RIGHT_VER);
				if (*(*(shape + i) + j + 1) == '#' && *(*(shape + i + 1) + j +
							1) == '#' && *(*(shape + i + 1) + j + 2) == '#')
					return (STAIRS_LEFT_HOR);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 1) + j -
							1) == '#' && *(*(shape + i + 2) + j - 1) == '#')
					return (STAIRS_LEFT_VER);
				if (*(*(shape + i) + j + 1) == '#' && *(*(shape + i) + j +
							2) == '#' && *(*(shape + i) + j + 3) == '#')
					return (BAR_HOR);
				if (*(*(shape + i + 1) + j) == '#' && *(*(shape + i + 2) + j)
						== '#' && *(*(shape + i + 3) + j) == '#')
					return (BAR_VER);
				return (UNKNOWN);
			}
			j++;
		}
		i++;
	}
}
