/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:30:23 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/18 12:39:03 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	init_game(char **map, t_lay lay)
{
	t_game	game;

	game.lay_bak = lay;
	game.n_collect_bak = lay.n_coin;
	game.map_bak = ft_matrixdup(map);	
	game.id = mlx_init();
	game.w_id = mlx_new_window(game.id, lay.n_col * SIZE, lay.n_row * SIZE + 80, "PROGRESSO YAAAY :D");
	new_game(map, &game, &lay);
}

void	new_game(char **map, t_game *game, t_lay *lay)
{
	game->n_frames = 1;
	game->n_moves = 0;
	game->width = lay->n_col * SIZE;
	game->height = lay->n_row * SIZE + 80;
	game->lay = lay;
	game->map = map;
	game->sprites = init_sprites(game);
}
