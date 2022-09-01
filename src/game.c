/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:30:23 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/31 14:43:26 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

int	key_hook(int key, t_game *game)
{	
	if (key == KEY_ESC)
	{
		printf("\n%sYou quit the game early!%s\n\n", RED, DEFAULT);
		end_game(game);
	}
	if ((key == KEY_UP || key == KEY_W) && game->next_dir != N)
		ft_newdirection(game, N);
	if ((key == KEY_DOWN || key == KEY_S) && game->next_dir != S)
		ft_newdirection(game, S);
	if ((key == KEY_RIGHT || key == KEY_D) && game->next_dir != E)
		ft_newdirection(game, E);
	if ((key == KEY_LEFT || key == KEY_A) && game->next_dir != W)
		ft_newdirection(game, W);
	return (0);
}

int	end_game(t_game *game)
{
	free_sprites(game);
	free_entitylist(game);
	ft_free_matrix(&game->map);
	ft_free_matrix(&game->map_bak);
	mlx_clear_window(game->id, game->w_id);
	mlx_destroy_window(game->id, game->w_id);
	printf("%sGame Finished!\n%sTotal Moves: %d\n\n%s", GREEN, \
		BLUE, game->n_moves, DEFAULT);
	exit(0);
	return (0);
}

void	init_game(char **map, t_lay lay)
{
	t_game	game;

	game.lay_bak = lay;
	game.n_collect_bak = lay.n_coin;
	game.map_bak = ft_matrixdup(map);
	game.id = mlx_init();
	game.w_id = mlx_new_window(game.id, lay.n_col * SIZE, \
			lay.n_row * SIZE + 80, "Puc-Man");
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
	mlx_put_image_to_window(game->id, game->w_id, \
			game->sprites.intra, game->height / 6 * -3, game->width / 8 * -1);
	game->pl = NULL;
	ft_entitylist(map, game);
	game->next_dir = 0;
	ft_load_pacmans(game);
	game->g_rate = GAME_RATE;
	game->redraw = 1;
	mlx_loop_hook(game->id, ft_update, (void *)game);
	mlx_hook(game->w_id, 17, 0, end_game, (void *)game);
	mlx_key_hook(game->w_id, key_hook, (void *)game);
	mlx_loop(game->id);
}

void	ft_check_game(t_game *game)
{
	ft_redraw_pac(game);
	if (game->next_dir)
		ft_next_dir(game);
	if (!game->lay->n_coin && !game->lay->n_pl)
	{
		printf("%sCONGRATULATIONS, YOU WIN!%s\n\n", GREEN, DEFAULT);
		end_game(game);
	}
}
