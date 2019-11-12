/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:10:21 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/12 14:24:58 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	add_size_info(char *line, t_info *info, int i)
{
	char	**split1;
	char	**split2;

	split1 = ft_strsplit(line, ':');
	split2 = ft_strsplit(split1[0], ' ');
	if (i == 0)
	{
		info->size_y = ft_atoi(split2[1]);
		info->size_x = ft_atoi(split2[2]);
	}
	if (i == 1)
	{
		info->piece_size_y = ft_atoi(split2[1]);
		info->piece_size_x = ft_atoi(split2[2]);
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

int			**add_piece_info(char *line, t_info *info)
{
	int		i;
	char	*new_line;
	int		**piece_map;

	add_size_info(line, info, 1);
	if (!(piece_map = malloc(sizeof(int *) * info->piece_size_y)))
		return ;
	i = 0;
	while (i < info->piece_size_y)
	{
		if (!(piece_map[i] = malloc(sizeof(int) * info->piece_size_x)))
			return ;
		i++;
	}
	i = 0;
	while (get_next_line(1, &new_line) > 0 && i < info->piece_size_y)
	{	
		make_piece_map(piece_map[i], new_line, info);
		i++;
		free(new_line);
	}
	return (piece_map);
}

void	init_info(t_info *info)
{
	info->size_x = 0;
	info->size_y = 0;
	info->x_or_o = 0;
	info->piece_size_x = 0;
	info->piece_size_y = 0;
	info->piece_map = NULL;
}

t_info  	*read_info_from_map(void)
{
	char    *line;
	t_info  *info;
	
	info = malloc(sizeof(t_info));
	init_info(info);
	while (get_next_line(1, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau ", 8) == 0)
			add_size_info(line, info, 0);
		else if (ft_strncmp(line, "Piece ", 6) == 0)
			info->piece_map = add_piece_info(line, info);
		free(line);
	}
	return (info);
}