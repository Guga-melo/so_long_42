/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:12:52 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/18 14:18:18 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_font	load_score_font(t_game *game)
{
	int	size;

	game->sprites.score_font.zero = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/0.xpm", &size, &size);
	game->sprites.score_font.one = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/1.xpm", &size, &size);
	game->sprites.score_font.two = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/2.xpm", &size, &size);
	game->sprites.score_font.three = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/3.xpm", &size, &size);
	game->sprites.score_font.four = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/4.xpm", &size, &size);
	game->sprites.score_font.five = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/5.xpm", &size, &size);
	game->sprites.score_font.six = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/6.xpm", &size, &size);
	game->sprites.score_font.seven = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/7.xpm", &size, &size);
	game->sprites.score_font.eight = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/8.xpm", &size, &size);
	game->sprites.score_font.nine = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/9.xpm", &size, &size);
	game->sprites.score_font.black = mlx_xpm_file_to_image(game->id, \
		"../sprites/Other/Fonts/black.xpm", &size, &size);
	return (game->sprites.score_font);
}

