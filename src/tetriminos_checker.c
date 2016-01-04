/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:24:09 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 08:17:27 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		transform_and_check(char *tetri, char id, int index)
{
	int		result;

	result = 0;
	if (tetri[index] == '#' && index >= 0 && index <= 20 && result <= 4)
	{
		result++;
		tetri[index] = id + 'a';
		result += transform_and_check(tetri, id, index + 1);
		result += transform_and_check(tetri, id, index - 1);
		result += transform_and_check(tetri, id, index + 5);
		result += transform_and_check(tetri, id, index - 5);
	}
	return (result);
}

static int		internal_check(char *tetri, int id)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (tetri[i])
	{
		if (tetri[i] == '.')
			k++;
		else if (tetri[i] == '#')
			j = transform_and_check(tetri, id, i);
		i++;
	}
	return (i == 20 && j == 4 && k == 12);
}

char			*check_tetriminos(char *tetri, int id)
{
	if (internal_check(tetri, id))
		return (tetri);
	else
	{
		ft_error();
		return (NULL);
	}
}
