/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:05:08 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/14 17:28:08 by bel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	*result;
	char	*shapes;

	if (argc == 2)
	{
		shapes = prepare_fill(*(argv + 1));
		if (shapes == NULL)
		{
			write(1, "error\n", 5);
			return (0);
		}
		printf("%s\n", shapes);
		result = fillit(shapes);
		//write(1, result, ft_strlen(result));
	}
	else
		write(1, "error\n", 5);
	return (0);
}
