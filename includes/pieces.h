/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pieces.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bel-baz <bel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 15:12:42 by bel-baz           #+#    #+#             */
/*   Updated: 2015/12/15 15:52:13 by bel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECES_H
# define PIECES_H
# define UNKNOWN 0
# define CROWN_UP 1
# define CROWN_DOWN 2
# define CROWN_RIGHT 3
# define CROWN_LEFT 4
# define L_LEFT_UP 5
# define L_LEFT_DOWN 6
# define L_LEFT_RIGHT 7
# define L_LEFT_LEFT 8
# define L_RIGHT_UP 9
# define L_RIGHT_DOWN 10
# define L_RIGHT_RIGHT 11
# define L_RIGHT_LEFT 12
# define STAIRS_LEFT_HOR 13
# define STAIRS_LEFT_VER 14
# define STAIRS_RIGHT_HOR 15
# define STAIRS_RIGHT_VER 16
# define BAR_HOR 17
# define BAR_VER 18
# define SQUARE 19

char	get_piece(char **shape);
#endif
