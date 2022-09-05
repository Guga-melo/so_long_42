/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghost.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 08:41:09 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/05 08:49:00 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_load_ghosts(t_game *game)
{
	t_player	*ghost;
	int			i;

	i = 0;
	ghost = game->gh;
	while (ghost)
	{
		ghost->sprites.up = ft_load_north(game, i);
		ghost->sprites.up_bak = ghost->sprites.up;
		ghost->sprites.down = ft_load_south(game, i);
		ghost->sprites.down_bak = ghost->sprites.down;
		ghost->sprites.left = ft_load_west(game, i);
		ghost->sprites.left_bak = ghost->sprites.left;
		ghost->sprites.right = ft_load_east(game, i);
		ghost->sprites.right_bak = ghost->sprites.right;
		ghost = ghost->next;
	}
}
