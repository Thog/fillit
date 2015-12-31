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
# define BUFF_SIZE 546

char	*ft_strsub(const char *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
char	*read_file(char *file);
void	ft_error(void);
void	fillit(char *fname);
char	*check_tetriminos(char *tetri, int id);
int		side_size(char *str);
int		min_grid_size(int tetriminos_nb);
void	fill_grid(char *grid, int size);
void	solve_tetriminos(char **tetris, int id);
size_t	ft_strlen(const char *s);
char	*resize_grid(char *grid, int size);
void	reset_grids(char *grid, char *tetris, int i, int j);
char	*ft_strdup(const char *s);
int		ft_isalpha(int c);
#endif
