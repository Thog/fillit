/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 19:37:07 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/02 19:53:13 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size_file(char *file)
{
	int		fd2;
	char	buffer;
	int		size;

	size = 0;
	fd2 = open(file, O_RDONLY);
	if (fd2 < 1)
		return (0);
	while (read(fd2, &buffer, 1))
		size++;
	if (close(fd2) == -1)
		return (0);
	return (size);
}

char	*read_file(char *file)
{
	int		fd;
	int		i;
	char	*result;
	char	buffer[1];

	i = size_file(file);
	fd = open(file, O_RDWR);
	if (fd > 2 && i != 0)
	{
		result = (char *)malloc(i + 1);
		if (result == NULL)
			return (NULL);
		i = -1;
		while (read(fd, &buffer, 1))
			result[++i] = buffer[0];
		if (close(fd) == -1)
			return (NULL);
		result[++i] = '\0';
		return (result);
	}
	return (NULL);
}
