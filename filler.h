/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <stanaka@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:10:35 by stanaka           #+#    #+#             */
/*   Updated: 2019/11/12 12:10:47 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H

#include "libft.h"

typedef struct	s_info
{
	int			size_x;
	int			size_y;
	char			x_or_o;
	int			fd;
}				t_info;

#endif