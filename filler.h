/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:10:35 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/12 14:22:21 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

typedef struct	s_info
{
	int			size_x;
	int			size_y;
	char		x_or_o;
	//int			fd;??
	int			piece_size_x;
	int			piece_size_y;
	int			**piece_map;	
}				t_info;

#endif