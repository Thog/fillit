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
	char	*buffer;

	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	buffer = ft_strnew(BUFF_SIZE);
	ft_bzero(buffer, BUFF_SIZE);
	if (read(fd, buffer, BUFF_SIZE) < 0)
		ft_error();
	if (ft_strlen(buffer) < 20 || buffer[BUFF_SIZE - 1] != '\0')
		ft_error();
	if (buffer[ft_strlen(buffer) - 1] == '\n' && (buffer[ft_strlen(buffer) - 2] != '.'
				&& buffer[ft_strlen(buffer) - 2] != '#'))
	{
		ft_error();
	}
	close(fd);
	return (buffer);
}
