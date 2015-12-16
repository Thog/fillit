/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:05:08 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/16 15:42:36 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

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
		result = fillit(pieces);
	}
	else
		write(1, "error\n", 5);
	return (0);
}
