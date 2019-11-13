/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:50:45 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/13 15:31:33 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//$$$ exec pPLAYER_NUMBER : [PLAYER_NAME]

#include "filler.h"


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
	int		n_piece;
	int		n_heatmap;
	
	info = malloc(sizeof(t_info));
	init_info(info);
	while (get_next_line(1, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau ", 8) == 0)
			add_size_info(line, info, 0);
		else if (ft_strncmp(line, "Piece ", 6) == 0)
			info->piece_map = add_piece_info(line, info);
		else if (line && line[0] >= '0' && line[0] <= '9')
			make_heatmap(line, info);
		else if (line && (line[0] == '*' || line[0] == '.'))
			make_piece(line, info);//done?
		free(line);
	}
	return (info);
}

int	main(int ac, char **av)
{
	t_info	*info;
	int		**map;
	
	while (1)
	{
		info = read_info_from_map();
		map = init_map(info);
	}
	return (0);
}