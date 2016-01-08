/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 08:15:39 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 08:16:20 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			side_size(t_cell *str)
{
	int		i;

	i = 0;
	while (str[i]->data != '\n')
		i++;
	return (i);
}

int			min_grid_size(int tetriminos_nb)
{
	int side;

	side = 2;
	while ((tetriminos_nb * 4) > (side * side))
		side++;
	return (side);
}

void		fill_grid(t_cell *grid, int size)
{
	int		i;

	i = 0;
	while (i < (size * size) + size)
	{
		grid[i]->data = '.';
		if (i > 0 && (i + 1) % (size + 1) == 0)
			grid[i]->data = '\n';
		i++;
	}
}

t_cell		*resize_grid(t_cell *grid, int size)
{
	t_cell	*tmp;
	int		i;
	int		j;

	j = 0;
	i = 0;
	tmp = ft_strnew((size * size) + size);
	fill_grid(tmp, size);
	while (grid[i])
	{
		if (grid[i]->data != '\n')
			tmp[j] = grid[i];
		else if (grid[i]->data == '\n')
		{
			tmp[j]->data = '.';
			j++;
			tmp[j] = grid[i];
		}
		i++;
		j++;
	}
	free(grid);
	return (tmp);
}

void		reset_grids(t_cell *grid, t_tetrimino *tetris, int i, int j)
{
	while (grid[i])
	{
		if (grid[i]->data == ('A' + j))
			grid[i]->data = '.';
		i++;
	}
	i = 0;
	while (tetris[i])
	{
		if (tetris[i]->data == ('A' + j))
			tetris[i]->data += 32;
		i++;
	}
}
