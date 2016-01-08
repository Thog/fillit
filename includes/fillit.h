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

typedef struct s_tetrimino
{
	unsigned char data : 5;
} t_tetrimino;

typedef struct s_cell
{
	unsigned char data : 5;
} t_cell;

t_tetrimino	*ft_strsub(const t_tetrimino *s, unsigned int start, size_t len);
void	ft_bzero(void *s, size_t n);
char	*ft_strnew(size_t size);
char	*read_file(char *file);
void	ft_error(void);
void	fillit(char *fname);
t_tetrimino	*check_tetriminos(t_tetrimino *tetri, int id);
int		side_size(char *str);
int		min_grid_size(int tetriminos_nb);
void	fill_grid(t_cell *grid, int size);
void	solve_tetriminos(t_tetrimino **tetris, int id);
size_t	ft_strlen(const char *s);
t_cell	*resize_grid(t_cell *grid, int size);
void	reset_grids(t_cell *grid, t_tetrimino *tetris, int i, int j);
char	*ft_strdup(const char *s);
int		ft_isalpha(int c);
#endif
