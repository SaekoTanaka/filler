/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:09:33 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/13 18:00:00 by stanaka          ###   ########.fr       */
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

void	heatmap(t_info *info)
{
	make_heatmap(info);
	check_heatmap(info);	
}

void	put_value(t_info *info, int x, int y)
{
	if ()
}

void	make_heatmap(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->size_y)
	{
		x = 0;
		while (x < info->size_x)
		{
			if (info->map[y][x] <= 0)
				put_value(info, x, y);//put positive num
			x++;
		}
		y++;
	}
}