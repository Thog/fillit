/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:00:05 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/16 15:04:30 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	void *result;

	if (size == 0)
		return (NULL);
	result = malloc(sizeof(void *) * size);
	if (result == NULL)
		return (NULL);
	ft_bzero(result, size);
	return (result);
}
