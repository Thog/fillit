/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_algo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 08:15:22 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/05 14:19:53 by bel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int			place_mino(char *grid, char *tetris, int j, int i)
{
	int		t;
	int		size;

	size = side_size(grid);
	t = 0;
	if (i >= 0 && i <= 20 && j >= 0 && j <= ((size * size) + size - 1) &&
			grid[j] == '.' && tetris[i] >= 'a' && tetris != NULL)
	{
		tetris[i] -= 32;
		grid[j] = tetris[i];
		t++;
		t += place_mino(grid, tetris, j + 1, i + 1);
		t += place_mino(grid, tetris, j + (size + 1), i + 5);
		t += place_mino(grid, tetris, j - 1, i - 1);
	}
	return (t);
}

static int			free_with_return(void *p)
{
	free(p);
	return (1);
}

static int			internal_solve(char **grid, char **tetris, int i, int size)
{
	int		index[2];
	char	*tmp;

	if (tetris[i] == NULL)
		return (1);
	tmp = ft_strdup(*grid);
	index[0] = 0;
	index[1] = 0;
	while ((*grid)[index[0]])
	{
		while (!ft_isalpha(tetris[i][index[1]]))
			index[1]++;
		if (place_mino(*grid, tetris[i], index[0], index[1]) != 4)
		{
			index[1] = 0;
			reset_grids(*grid, tetris[i], index[0]++, i);
			continue ;
		}
		if (internal_solve(grid, tetris, i + 1, size))
			return (free_with_return(tmp));
		free(*grid);
		*grid = ft_strdup(tmp);
	}
	free(tmp);
	return (0);
}

void				solve_tetriminos(char **tetris, int id)
{
	char	*grid;
	int		grid_size;
	char	**local_tetris;

	local_tetris = tetris;
	grid_size = min_grid_size(id);
	grid = ft_strnew((grid_size * grid_size) + grid_size);
	fill_grid(grid, grid_size);
	while (!internal_solve(&grid, local_tetris, 0, grid_size))
	{
		grid = resize_grid(grid, ++grid_size);
	}
	write(1, grid, ft_strlen(grid));
	free(grid);
}
