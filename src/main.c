/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:05:08 by tguillem          #+#    #+#             */
/*   Updated: 2016/01/04 08:13:19 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_error(void)
{
	write(2, "error\n", 6);
	exit(EXIT_FAILURE);
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		fillit(argv[1]);
	else
	{
		write(2, "error\n", 6);
		return (EXIT_FAILURE);
	}
	return (0);
}
