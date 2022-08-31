/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_dir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 09:57:56 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/30 08:27:07 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_anim_north(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % (( game->g_rate + game->g_rate) / 7)))
		temp->sprites.up = temp->sprites.up->next;
	if (!temp->sprites.up)
		temp->sprites.up = temp->sprites.up_bak;
	mlx_put_image_to_window(game->id, game->w_id, game->sprites.black, \
			temp->win_pos.x, temp->win_pos.y);
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.up->content, \
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_south(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % ((game->g_rate + game->g_rate) / 7)))
		temp->sprites.down = temp->sprites.down->next;
	if (!temp->sprites.down)
		temp->sprites.down = temp->sprites.down_bak;
	mlx_put_image_to_window(game->id, game->w_id, game->sprites.black, \
			temp->win_pos.x, temp->win_pos.y);
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.down->content, \
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_east(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % ((game->g_rate + game->g_rate) / 7)))
		temp->sprites.right = temp->sprites.right->next;
	if (!temp->sprites.right)
		temp->sprites.right = temp->sprites.right_bak;
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.right->content, \
		temp->win_pos.x, temp->win_pos.y);
}

void	ft_anim_west(t_game *game, t_player *pl)
{
	t_player	*temp;

	temp = pl;
	if (!(game->n_frames % ((game->g_rate + game->g_rate) / 7)))
		temp->sprites.left = temp->sprites.left->next;
	if (!temp->sprites.left)
		temp->sprites.left = temp->sprites.left_bak;
	mlx_put_image_to_window(game->id, game->w_id, game->sprites.black, \
			temp->win_pos.x, temp->win_pos.y);
	mlx_put_image_to_window(game->id, game->w_id, temp->sprites.left->content, \
		temp->win_pos.x, temp->win_pos.y);
}
