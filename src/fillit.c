/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:22:59 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/17 11:52:56 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

char	*fillit(t_piece *pieces)
{
	char	*result;

	printf("%d\n", pieces->id);
	if (pieces == NULL || !(result = (char*)malloc(sizeof(char) * 730)))
		return ("");
	ft_bzero(result, 730);
	return (result);
}
