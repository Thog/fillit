/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:22:59 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/15 15:27:13 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*fillit(char *shapes)
{
	char	*result;

	if (shapes == NULL || !(result = (char*)malloc(sizeof(char) * 730)))
		return ("");
	ft_bzero(result, 730);
	return (result);
}
