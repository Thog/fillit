/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:19:06 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/08 12:00:01 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char				*read_file(char *file);
char				**prepare_fill(char *fname);
char				*fillit(char **shapes);
int					ft_strlen(const char *s);

typedef struct		s_pieces
{
	char			*data;
	int				x;
	int				y;
	int				width;
	int				height;
}					t_pieces;
#endif
