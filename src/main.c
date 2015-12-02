/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:05:08 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/02 17:32:53 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	main(int argc, char **argv)
{
	char	*result;
	char	**shapes;
	if (argc > 1)
	{
		shapes = prepare_fill(*(argv + 1));
		if (shapes == NULL)
		{
			write(1, "error\n", 5);
			return (0);
		}
		result = fillit(shapes);
		write(1, result, ft_strlen(result));	
	}
	return (0);
}
