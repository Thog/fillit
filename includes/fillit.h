/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillem <tguillem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 17:19:06 by tguillem          #+#    #+#             */
/*   Updated: 2015/12/21 02:20:17 by tguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
char	*read_file(char *file);
void	ft_error(void);
void	fillit(char *fname);
char	*check_tetriminos(char *tetri, int id);
void	solve_tetriminos(char **tetris, int id);
size_t	ft_strlen(const char *s);
#endif
