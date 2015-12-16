/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:19:06 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/16 15:43:45 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "pieces.h"

char				*read_file(char *file);
t_piece				*prepare_fill(char *fname);
int					draw_piece(char **board, int piece, int dx, int dy);
char				*fillit(t_piece *pieces);
int					ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
void				*ft_memalloc(size_t size);
#endif
