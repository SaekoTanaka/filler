/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:13:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/12 14:22:59 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			**init_map(t_info *info)
{
	int		**map;
	int		i;

	map = malloc(sizeof(int *) * info->size_y);
	if (map == NULL)
		return (NULL);
	i = 0;
	while (i < info->size_y)
	{
		map[i] = malloc(sizeof(int) * info->size_x);
		if (map[i] == NULL)
			return (NULL);
		i++;
	}
	return (map);
}

void	get_each_line_info(t_info *info, int **map, char *line, int y)
{
	int	x;
	char	**split;

	split = ft_strsplit(line, ' ');
	x = 0;
	while (split[1][x] != '\n')
	{
		if (split[1][x] == '.')
			map[y][x] = 0;
		else if (split[1][x] == (int)info->x_or_o || split[1][x] == (int)info->x_or_o + 32)
			map[y][x] = -1;
		else
			map[y][x] = -2;
		x++;		
	}
}

void	check_the_value(int y, int **map, t_info *info, int v)
{
	int		x;

	x = 0;
	while (x < info->size_x)
	{
		if (map[y][x] == v)
			put_the_value(map);		
		x++;
	}
}

void	put_heatmap_info(int **map, t_info *info)
{
	int	y;
	int	value;

	y = 0;
	value = -1;
	while (value < info->size_x + info->size_y)
	{
		while (y < info->size_y)
		{
			check_the_value(y, map, info, value);
			y++;
		}
		value++;
	}
}

void	make_heatmap(int **map, t_info *info)
{
	char	*line;
	int		y;

	y = 0;
	while (get_next_line(info->fd, &line) > 0)
	{
		get_each_line_info(info, map, line, y);
		free(line);
		y++;
	}
	put_heatmap_info(map, info);
}

void	position_shape(int **map, t_info *info)
{

}

