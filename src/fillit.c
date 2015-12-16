/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:22:59 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/16 15:43:36 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*fillit(t_piece *pieces)
{
	char	*result;

	if (pieces == NULL || !(result = (char*)malloc(sizeof(char) * 730)))
		return ("");
	ft_bzero(result, 730);
	return (result);
}
