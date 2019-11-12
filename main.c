/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 12:50:45 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/12 13:28:06 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//$$$ exec pPLAYER_NUMBER : [PLAYER_NAME]

#include "filler.h"

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