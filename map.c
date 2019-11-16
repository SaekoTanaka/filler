/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:09:33 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/15 17:59:23 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_map_line(char *line, t_info *info)//info already has map initial one
{
	int	y;

	y = 0;
	while (y < info->size_y)
	{
		if (info->map[y][0] == -3)
			break ;
		y++;
	}
	get_each_line_info(info, line, y);
}

t_p_p	*heatmap(t_info *info)
{
	t_p_p	*piece_pos;

	make_heatmap(info);
	piece_pos = check_piece_position(info);
	return (piece_pos);
}

void	put_value(t_info *info, int x, int y, int i)
{
	if (y != 0 && info->map[y - 1][x] == -3)
		info->map[y - 1][x] = i + 1;
	if (y != info->size_y - 1 && info->map[y + 1][x] == -3)
		info->map[y + 1][x] = i + 1;
	if (x != 0 && info->map[y][x - 1] == -3)
		info->map[y][x - 1] = i + 1;
	if (x != info->size_x - 1 && info->map[y][x + 1] == -3)
		info->map[y][x + 1] = i + 1;
}

void	make_heatmap(t_info *info)
{
	int	x;
	int	y;
	int	i;
	(void)info;

	i = 0;
	while (i < info->size_x + info->size_y)
	{
		y = 0;
		while (y < info->size_y)
		{
			x = 0;
			while (x < info->size_x)
			{
				if (info->map[y][x] == i)
					put_value(info, x, y, i);//put positive num
				x++;
			}
			y++;
		}
		i++;
	}
}