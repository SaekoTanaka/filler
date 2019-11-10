/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stanaka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 09:04:13 by stanaka           #+#    #+#             */
/*   Updated: 2019/03/07 16:14:49 by stanaka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalnum(int n)
{
	if (ft_isdigit(n) == 1 || ft_isalpha(n) == 1)
	{
		return (1);
	}
	return (0);
}
