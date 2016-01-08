/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:22:59 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 08:12:56 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		free_tetriminos(char **tetris)
{
	int	i;

	i = 0;
	while (tetris[i] != NULL)
	{
		free(tetris[i]);
		i++;
	}
	free(tetris);
}

void			fillit(char *fname)
{
	t_tetrimino	**tetris;
	t_tetrimino	*fcontent;
	int		i;
	int		j;

	i = 20;
	j = 0;
	fcontent = read_file(fname);
	tetris = (t_tetrimino **)malloc(sizeof(t_tetrimino*) * 27);
	while (fcontent[++i])
	{
		if (!(i % 21))
		{
			tetris[j] = check_tetriminos(ft_strsub(fcontent, i - 21, 20), j);
			j++;
		}
	}
	if (!fcontent[i])
		tetris[j] = check_tetriminos(ft_strsub(fcontent, i - 21, 20), j);
	tetris[j + 1] = NULL;
	free(fcontent);
	solve_tetriminos(tetris, j);
	free_tetriminos(tetris);
}
