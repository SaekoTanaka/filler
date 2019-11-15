/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:50:45 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/14 17:31:01 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//$$$ exec pPLAYER_NUMBER : [PLAYER_NAME]

#include "filler.h"

void	init_info(t_info *info)
{
	info->size_x = 0;
	info->size_y = 0;
	info->x_or_o = 79;
	info->piece_size_x = 0;
	info->piece_size_y = 0;
	info->piece_map = NULL;
	info->map = NULL;
}

void	clean_info(t_info *info)
{
	if (info->x_or_o == 88)
		info->x_or_o = 79;
	else
		info->x_or_o = 88;
	info->size_x = 0;
	info->size_y = 0;
	info->piece_size_x = 0;
	info->piece_size_y = 0;
	info->piece_map = NULL;
	info->map = NULL;
}

t_info  	*read_info_from_map(void)
{
	char    *line;
	t_info  *info;
	
	info = NULL;
	while (get_next_line(1, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau ", 8) == 0)
			add_size_info(line, info, 0);
		else if (ft_strncmp(line, "Piece ", 6) == 0)
			info->piece_map = add_piece_info(line, info);
		else if (line && line[0] >= '0' && line[0] <= '9')
			make_map_line(line, info);
		else if (line && (line[0] == '*' || line[0] == '.'))
			make_piece(line, info);
		free(line);
	}
	return (info);
}

void	re_write(t_p_p *p_p)
{
	char	*x;
	char	*y;

	x = ft_itoa(p_p->x);
	y = ft_itoa(p_p->y);
	ft_putstr(x);
	ft_putchar(' ');
	ft_putstr(y);
	ft_putchar('\n');
}

void	free_maps(t_info *info)
{
	int	y;

	y = 0;
	while (y < info->size_y)
	{
		free(info->map[y]);
		y++;
	}
	free(info->map);
	y = 0;
	while (y < info->piece_size_y)
	{
		free(info->piece_map[y]);
		y++;
	}
	free(info->piece_map);
}

int	main(int ac, char **av)
{
	t_info	*info;
	t_p_p	*p_p;
	
	(void)ac;
	(void)av;
	info = malloc(sizeof(t_info));
	init_info(info);
	while (1)
	{
		info = read_info_from_map();
		p_p = heatmap(info);
		if (p_p->min == -1)
			break ;
		re_write(p_p);
		free_maps(info);
		clean_info(info);
		free(p_p);
	}
	return (0);
}
