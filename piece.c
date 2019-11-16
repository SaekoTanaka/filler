/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:09:36 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/15 15:27:24 by stanaka          ###   ########.fr       */
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
		if (info->piece_map[i][0] == -1)
			break ;
		i++;
	}
	make_piece_map(info->piece_map[i], line, info);
}

int			**add_piece_info(char *line, t_info *info)
{
	int		i;
	int		**piece_map;

	add_size_info(line, info, 1);
	if (!(piece_map = malloc(sizeof(int *) * info->piece_size_y)))
		return (NULL);
	i = 0;
	while (i < info->piece_size_y)
	{
		if (!(piece_map[i] = malloc(sizeof(int) * info->piece_size_x)))
			return (NULL);
		i++;
	}
	piece_map_init(piece_map, info);
	//i = 0;
	//while (get_next_line(1, &new_line) > 0 && i < info->piece_size_y)
	//{	
	//	make_piece_map(piece_map[i], new_line, info);
	//	i++;
	//	free(new_line);
	//}
	return (piece_map);
}

int		piece_is_valid(t_info *info, int x, int y)
{
	int	n;
	int	ix;
	int iy;

	n = 0;
	iy = 0;
	while (iy < info->piece_size_y)
	{
		ix = 0;
		while (ix < info->piece_size_x)
		{
			if (info->map[y + iy][x + ix] == -2 && info->piece_map[iy][ix] == 1)
				n++;
			ix++;
		}
		iy++;
	}
	return (n);
}