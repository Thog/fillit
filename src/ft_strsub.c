/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 08:53:39 by tguillem          #+#    #+#             */
/*   Updated: 2015/11/26 11:37:47 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

t_tetrimino	*ft_strncpy(t_tetrimino *s1, const t_tetrimino *s2, size_t n)
{
	unsigned int		i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i]->data = s2[i]->data;
		i++;
	}
	while (i < n)
	{
		s1[i]->data = '\0';
		i++;
	}
	return (s1);
}

t_tetrimino	*ft_strsub(const t_tetrimino *s, unsigned int start, size_t len)
{
	t_tetrimino	*result;

	result = (t_tetrimino *)malloc(sizeof(t_tetrimino) * (len + 1));
	if (!result)
		return (NULL);
	result = ft_strncpy(result, (s + start), len);
	result[len]->data = '\0';
	return (result);
}
