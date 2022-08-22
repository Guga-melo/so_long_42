/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 08:22:34 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/22 09:40:37 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_entitylist(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				ft_entadd_back(&game->pl, ft_entnew(ft_newvector(x, y)));
			if (map[y][x] == 'G')
				ft_entadd_back(&game->pl, ft_entnew(ft_newvector(x, y)));
			x++;
		}
		y++;
	}
}
