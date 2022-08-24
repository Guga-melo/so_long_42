/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 12:35:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/23 14:04:25 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_sprite	init_sprites(t_game *game)
{
	int size;

	size = SIZE;
	game->sprites.pacman = mlx_xpm_file_to_image(game->id, \
			"sprites/Pac-Man/pac_closed.xpm", &size, &size);
	game->sprites.pacfood = mlx_xpm_file_to_image(game->id, \
			"sprites/Other/Pacdots/pacdot_food.xpm", &size, &size);
	game->sprites.pacpower = mlx_xpm_file_to_image(game->id, \
			"sprites/Other/Pacdots/pacdot_powerup.xpm", &size, &size);
	game->sprites.logo = mlx_xpm_file_to_image(game->id, \
			"sprites/Other/Logo/logo.xpm", &size, &size);
	game->sprites.black = mlx_xpm_file_to_image(game->id, \
			"sprites/Pac-Man/black.xpm", &size, &size);
	game->sprites.wall = mlx_xpm_file_to_image(game->id, \
			"sprites/Other/Walls/wall.xpm", &size, &size);
	game->sprites.portal = mlx_xpm_file_to_image(game->id, \
			"sprites/Other/Portal/portal.xpm", &size, &size);
	game->sprites.pac_dying = load_pac_death(game);
	game->sprites.pac_dying_bak = game->sprites.pac_dying;
	game->sprites.score_font = load_score_font(game);
	return (game->sprites);
}

int	free_sprites(t_game *game)
{
	mlx_destroy_image(game->id, game->sprites.wall);
	mlx_destroy_image(game->id, game->sprites.pacfood);
	mlx_destroy_image(game->id, game->sprites.pacpower);
	mlx_destroy_image(game->id, game->sprites.portal);
	mlx_destroy_image(game->id, game->sprites.logo);
	mlx_destroy_image(game->id, game->sprites.pacman);
	mlx_destroy_image(game->id, game->sprites.black);
	free_players(game);
	free_fonts(game);
	free_animation(game, game->sprites.pac_dying_bak);
	return (0);
}

void	free_players(t_game *game)
{
	t_player	*ghost;
	t_player	*pacman;

	ghost = game->gh;
	pacman = game->pl;
	while (ghost)
	{
		free_animation(game, ghost->sprites.up_bak);
		free_animation(game, ghost->sprites.down_bak);
		free_animation(game, ghost->sprites.left_bak);
		free_animation(game, ghost->sprites.right_bak);
		free_animation(game, ghost->sprites.panic_bak);
		ghost = ghost->next;
	}
	while (pacman)
	{
		free_animation(game, pacman->sprites.up_bak);
		free_animation(game, pacman->sprites.down_bak);
		free_animation(game, pacman->sprites.left_bak);
		free_animation(game, pacman->sprites.right_bak);
		pacman = pacman->next;
	}
}

void	ft_free_singlepl(t_game *game, t_player *pl)
{
	free_animation(game, pl->sprites.up_bak);
	free_animation(game, pl->sprites.down_bak);
	free_animation(game, pl->sprites.left_bak);
	free_animation(game, pl->sprites.right_bak);
}

void	ft_put_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.wall, \
			x * SIZE, y * SIZE);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.portal, \
			x * SIZE, y * SIZE);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacfood, \
			x * SIZE, y * SIZE);
	if (game->map[y][x] == 'W')
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.pacpower, \
			x * SIZE, y * SIZE);
}
