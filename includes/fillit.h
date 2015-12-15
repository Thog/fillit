/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:19:06 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/15 11:43:09 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char				*read_file(char *file);
char				*prepare_fill(char *fname);
char				*fillit(char *shapes);
int					ft_strlen(const char *s);
void				ft_bzero(void *s, size_t n);
#endif
