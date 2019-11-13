/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:09:36 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/13 15:30:47 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

void	piece_map_init(int **piece_map, t_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < info->piece_size_y)
	{
		j = 0;
		while (j < info->piece_size_x)
		{
			piece_map[i][j] = -1;
			j++;
		}
		i++;
	}
}

void	make_piece_map(int *piece_map_line, char *new_line, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->piece_size_x)
	{
		if (new_line[i] == '*')
			piece_map_line[i] = 1;
		else
			piece_map_line[i] = 0;// '.'		
		i++;
	}
}

void	make_piece(char *line, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->piece_size_y)
	{
		if (info->piece_map[i] == -1)
			break ;
		i++;
	}
	make_piece_map(info->piece_map[i], line, info);
}
