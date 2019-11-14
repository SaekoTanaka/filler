/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:10:35 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/14 15:08:27 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

typedef struct	s_info
{
	int			size_x;
	int			size_y;
	char		x_or_o;
	//int			fd;??
	int			piece_size_x;
	int			piece_size_y;
	int			**map;
	int			**piece_map;	
}				t_info;

typedef struct	s_piece_pos
{
	int			x;
	int			y;
	int			min;
}				t_p_p;

//algo.c
int		**init_map(t_info *info);
void	get_each_line_info(t_info *info, char *line, int y);
void	check_the_value(int y, int **map, t_info *info, int v);//
void	put_heatmap_info(int **map, t_info *info);//
void	shape_position(t_info *info);
t_p_p	*check_piece_position(t_info *info);

//main.c
t_info  *read_info_from_map(void);
void	init_info(t_info *info);
void	switch_x_o(t_info *info);

//piece.c
void	piece_map_init(int **piece_map, t_info *info);
void	make_piece_map(int *piece_map_line, char *new_line, t_info *info);
void	make_piece(char *line, t_info *info);
int		**add_piece_info(char *line, t_info *info);
int		piece_is_valid(t_info *info, int x, int y);

//read_info.c
void	add_size_info(char *line, t_info *info, int i);

//map.c
t_p_p	*heatmap(t_info *info);
void	make_map_line(char *line, t_info *info);
void	make_heatmap(t_info *info);

#endif