/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:35:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/18 14:02:19 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_sprite	init_sprites(t_game *game)
{
	int size;

	size = SIZE;
	game->sprites.pacman = mlx_xpm_file_to_image(game->id, \
			"../sprites/Pac-Man/pac_closed.xpm", &size, &size);
	game->sprites.pacfood = mlx_xpm_file_to_image(game->id, \
			"../sprites/Other/Pacdots/pacdot_food.xpm", &size, &size);
	game->sprites.pacpower = mlx_xpm_file_to_image(game->id, \
			"../sprites/Other/Pacdots/pacdot_powerup.xpm", &size, &size);
	game->sprites.logo = mlx_xpm_file_to_image(game->id, \
			"../sprites/Other/Logo/logo.xpm", &size, &size);
	game->sprites.black = mlx_xpm_file_to_image(game->id, \
			"../sprites/Pac-Man/black.xpm", &size, &size);
	game->sprites.wall = mlx_xpm_file_to_image(game->id, \
			"../sprites/Other/Walls/wall.xpm", &size, &size);
	game->sprites.portal = mlx_xpm_file_to_image(game->id, \
			"../sprites/Other/Portal/portal.xpm", &size, &size);
	game->sprites.pac_dying = load_pac_death(game);
	game->sprites.pac_dying_bak = game->sprites.pac_dying;
	game->sprites.score_font = load_score_font(game);
	return (game->sprites);
}
