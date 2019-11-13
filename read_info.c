/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:10:21 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/13 15:26:02 by stanaka          ###   ########.fr       */
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
