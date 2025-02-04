/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:10:21 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/15 17:44:22 by stanaka          ###   ########.fr       */
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
		info->map = init_map(info);
	}
	if (i == 1)
	{
		info->piece_size_y = ft_atoi(split2[1]);
		info->piece_size_x = ft_atoi(split2[2]);
	}
}

void	make_player(char *line, t_info *info)
{
	char	**split;

	split = ft_strsplit(line, ' ');
	if (split[2][1] == '1')
		info->player = 79;
	else
		info->player = 88;	
}