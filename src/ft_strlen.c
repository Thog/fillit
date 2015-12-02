/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:21:12 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/02 17:22:31 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	ft_strlen(const char *s)
{
	int	counter;

	counter = 1;
	while (s[counter])
		counter++;
	if (!s[0])
		return (0);
	return (counter);
}
