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
	char	*buff;

	i = size_file(file);
	fd = open(file, O_RDWR);
	if ((fd = open(file, O_RDONLY)) < 0)
		ft_error();
	buff = ft_strnew(i);
	if (read(fd, buff, i) < 0)
		ft_error();
	if (ft_strlen(buff) < 20 || buff[i - 1] != '\0')
		ft_error();
	if (buff[ft_strlen(buff) - 1] == '\n' && (buff[ft_strlen(buff) - 2] != '.'
				&& buff[ft_strlen(buff) - 2] != '#'))
		ft_error();
	close(fd);
	return (buff);
}
