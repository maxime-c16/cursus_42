/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:05:40 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/16 11:07:34 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_list	*_lst(void)
{
	static int		init = 0;
	static t_list	map;

	if (init == 0)
	{
		ft_bzero(&map, sizeof(map));
		init = 1;
	}
	return (&map);
}
