/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 01:57:07 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/21 02:27:32 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_piece		*alloc_piece(char letter, int id)
{
	t_piece		*result;

	if (!(result = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	result->id = id;
	result->letter = letter;
	return (result);
}

void		piece_add(t_piece **piece, t_piece *node)
{
	if (*piece)
		(*piece)->next = node;
	else
		*piece = node;
}
