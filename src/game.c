/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:30:23 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/22 13:42:06 by gussoare         ###   ########.fr       */
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
	game.w_id = mlx_new_window(game.id, lay.n_col * SIZE, lay.n_row * SIZE + 80, "Puc-Man");
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
	game->pl = NULL;
	game->gh = NULL;
	ft_entitylist(map, game);
	game->next_dir = 0;
	ft_load_ghosts(game);
	ft_load_pacmans(game);
	game->pac_dying = 0;
	game->panic_mode = 0;
	game->g_rate = GAME_RATE;
	game->redraw = 1;
	mlx_loop_hook(game->id, ft_update, (void *)game);
}

void	ft_check_game(t_game *game)
{
	if (game->lay_bak.n_coin / 4 + 1 >= game->lay->n_coin && game->lay->n_gh)
	{
		if (!game->panic_mode)
			game->g_rate -= game->g_rate / 3;
		game->panic_mode = 1;
	}
	if (!(game->n_frames % 2) || game->panic_mode || !(game->n_frames % 3))
		ft_redraw_gh(game);
	if (!game->pac_dying)
		ft_redraw_pac(game);
	if (game->pl->dir != ST && !game->pac_dying)
		ft_update_ghosts(game);
	if (game->next_dir)
		ft_next_dir(game);
	if (game->pac_dying && !(game->n_frames % 9))
		ft_anim_pacdeath(game);
	if (!game->lay->n_coin && !game->lay->n_pl && !game->pac_dying)
	{
		printf("%sCONGRATULATIONS, YOU WIN!%s\n\n", GREEN, DEFAULT);
		end_game(game);
	}
}
