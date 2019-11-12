/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:10:21 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/12 12:25:38 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_info  *read_info_from_map(void)
{
    char    *line;
    t_info  *info;
    
    info = malloc(sizeof(t_info));
    while (get_next_line(1, &line) > 0)
    {
        if (ft_strcmp())
    }
    return (info);
}