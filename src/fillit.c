/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:22:59 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/17 17:29:23 by bel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	**alloc_grid()
{
	int		i;
	char 	**result;

	i = 0;
	if ((result = (char**)malloc(sizeof(char*) * 730)) == NULL)
		return (NULL);
	while (i < 730)
	{
		if ((*(result + i) = (char*)malloc(sizeof(char) * 730)) == NULL)
			return (NULL);
		i++;
	}
	return (result);
}

char	**fillit(t_piece *pieces)
{
	char	**result;

	printf("%d\n", pieces->id);
	if (pieces == NULL || !(result = alloc_grid()))
		return (NULL);
	ft_bzero(result, 730);
	return (result);
}
