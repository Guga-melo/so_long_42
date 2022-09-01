/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:45:11 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/31 14:40:17 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_redraw_pac(t_game *game)
{
	t_player	*pl;

	pl = game->pl;
	while (pl)
	{
		if (pl->win_pos.x < pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x += 2;
		if (pl->win_pos.x > pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x -= 2;
		if (pl->win_pos.y < pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y += 2;
		if (pl->win_pos.y > pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y -= 2;
		if (pl->win_pos.x == pl->pos.x * SIZE && \
				pl->win_pos.y == pl->pos.y * SIZE)
			pl->moving = 0;
		pl = pl->next;
	}
	ft_put_pacman(game);
}

void	ft_put_stopped(t_game *g, t_player *pl)
{
	if (pl->dir == N)
		mlx_put_image_to_window(g->id, g->w_id, pl->sprites.up_bak->content, \
			pl->pos.x * SIZE, pl->pos.y * SIZE);
	if (pl->dir == S)
		mlx_put_image_to_window(g->id, g->w_id, pl->sprites.down_bak->content, \
			pl->pos.x * SIZE, pl->pos.y * SIZE);
	if (pl->dir == E)
		mlx_put_image_to_window(g->id, g->w_id, pl->sprites.right_bak->content, \
			pl->pos.x * SIZE, pl->pos.y * SIZE);
	if (pl->dir == W)
		mlx_put_image_to_window(g->id, g->w_id, pl->sprites.left_bak->content, \
			pl->pos.x * SIZE, pl->pos.y * SIZE);
}
