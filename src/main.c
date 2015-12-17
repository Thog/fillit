/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:05:08 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/17 16:28:46 by bel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void    disp_pieces(t_piece *pieces)
{
	while (pieces)
	{
		printf("%s",&(pieces->letter));
		printf(" %d\n",(pieces->id));
		pieces = pieces->next;
	}
}

int	main(int argc, char **argv)
{
	char	*result;
	t_piece	*pieces;

	if (argc == 2)
	{
		if (!(pieces = prepare_fill(*(argv + 1))))
		{
			write(1, "error\n", 5);
			return (0);
		}
		disp_pieces(pieces);
		result = fillit(pieces);
	}
	else
		write(1, "error\n", 5);
	return (0);
}
