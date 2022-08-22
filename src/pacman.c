/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pacman.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:11:45 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/22 13:13:34 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_load_pacmans(t_game *game)
{
	t_player	*pacman;
	int			i;

	i = 0;
	pacman = game->pl;
	while (pacman)
	{
		pacman->sprites.up = ft_load_north(game, NULL, i);
		pacman->sprites.up_bak = pacman->sprites.up;
		pacman->sprites.down = ft_load_south(game, NULL, i);
		pacman->sprites.down_bak = pacman->sprites.down;
		pacman->sprites.left = ft_load_west(game, NULL, i);
		pacman->sprites.left_bak = pacman->sprites.left;
		pacman->sprites.right = ft_load_east(game, NULL, i);
		pacman->sprites.right_bak = pacman->sprites.right;
		pacman = pacman->next;
	}
}
