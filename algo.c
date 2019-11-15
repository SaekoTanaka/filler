/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:13:38 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/14 17:17:25 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_dot(t_info *info)
{
	int	x;
	int	y;

	y = 0;
	while (y < info->size_y)
	{
		x = 0;
		while (x < info->size_x)
		{
			info->map[y][x] = -3;
			x++;
		}
		y++;
	}
}

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
	init_dot(info);
	return (map);
}

void	get_each_line_info(t_info *info, char *line, int y)
{
	int		x;
	char	**split;

	split = ft_strsplit(line, ' ');
	if (split[1] == NULL)
		return ;
	x = 0;
	while (split[1][x] != '\0')//'.'== -3, 'x' == 0 or -2 
	{
		//if (split[1][x] == '.')
		//	info->map[y][x] = 0;
		//else if (split[1][x] == (int)info->x_or_o || split[1][x] == (int)info->x_or_o + 32)
		if (split[1][x] == info->x_or_o || split[1][x] == info->x_or_o + 32)
			info->map[y][x] = 0;
		else if (split[1][x] != '.')
			info->map[y][x] = -2;
		x++;		
	}
}

void	compare_piece_postion(t_p_p *min, t_info *info, int x, int y)
{
	int	total;
	int	ix;
	int	iy;

	total = 0;
	iy = 0;
	while (iy < info->piece_size_y)
	{
		ix = 0;
		while (ix < info->piece_size_x)
		{
			total += info->map[y + iy][x + ix] * info->piece_map[iy][ix];
			ix++;
		}
		iy++;
	}
	if (min->min > total)
	{
		min->x = x;
		min->y = y;
		min->min = total;
	}
}


t_p_p		*check_piece_position(t_info *info)
{
	int	y;
	int	x;
	t_p_p	*min;
	
	if (!(min == malloc(sizeof(t_p_p))))
		return (NULL);
	min->x = -1;
	min->y = -1;
	min->min = -1;
	y = 0;
	while (y <= info->size_y - info->piece_size_y)
	{
		x = 0;
		while (x <= info->size_x - info->piece_size_x)
		{
			if (piece_is_valid(info, x, y) == 1)//piece pos is valid or not
				compare_piece_position(min, info, x, y);
			x++;
		}
		y++;
	}
	return (min);
}


//void	check_the_value(int y, int **map, t_info *info, int v)
//{
//	int		x;
//
//	x = 0;
//	while (x < info->size_x)
//	{
//		if (map[y][x] == v)
//			put_the_value(map);		
//		x++;
//	}
//}

//void	put_heatmap_info(int **map, t_info *info)
//{
//	int	y;
//	int	value;
//
//	y = 0;
//	value = -1;
//	while (value < info->size_x + info->size_y)
//	{
//		while (y < info->size_y)
//		{
//			check_the_value(y, map, info, value);
//			y++;
//		}
//		value++;
//	}
//}

//void	make_heatmap(int **map, t_info *info)
//{
//	char	*line;
//	int		y;
//
//	y = 0;
//	while (get_next_line(1, &line) > 0)
//	{
//		get_each_line_info(info, map, line, y);
//		free(line);
//	 	y++;
//	}
//	put_heatmap_info(map, info);
//}
