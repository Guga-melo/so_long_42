/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:07:19 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/31 14:34:36 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_move(int d, t_game *game, t_player *temp)
{
	t_vector	nw;

	if (temp)
	{
		if (d == N && ft_strchr("0CE", game->map[temp->pos.y - 1][temp->pos.x]))
			nw = ft_newvector(temp->pos.x, temp->pos.y - 1);
		else if (d == S && ft_strchr("0CE", \
				game->map[temp->pos.y + 1][temp->pos.x]))
			nw = ft_newvector(temp->pos.x, temp->pos.y + 1);
		else if (d == E && ft_strchr("0CE", \
				game->map[temp->pos.y][temp->pos.x + 1]))
			nw = ft_newvector(temp->pos.x + 1, temp->pos.y);
		else if (d == W && ft_strchr("0CE", \
				game->map[temp->pos.y][temp->pos.x - 1]))
			nw = ft_newvector(temp->pos.x - 1, temp->pos.y);
		else
			nw = ft_newvector(0, 0);
		if (game->map[nw.y][nw.x] == 'C')
			game->lay->n_coin--;
		if (nw.x && nw.y)
			ft_swap_tile(ft_newvector(temp->pos.x, temp->pos.y), nw, game);
	}
}

int	ft_swap_tile(t_vector old, t_vector nw, t_game *game)
{
	t_player	*player;
	int			hide;

	player = game->pl;
	hide = 0;
	if (game->map[nw.y][nw.x] == 'E')
	{
		if (game->lay->n_coin)
			return (1);
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.black, \
			old.x * SIZE, old.y * SIZE);
		hide = ft_delete_entity(game, old);
	}
	while (!hide && player)
	{
		if (player->pos.x == old.x && player->pos.y == old.y)
		{
			player->pos = ft_newvector(nw.x, nw.y);
			player->moving = 1;
		}
		player = player->next;
	}
	ft_memset(&game->map[nw.y][nw.x], game->map[old.y][old.x], !hide);
	ft_memset(&game->map[old.y][old.x], '0', 1);
	return (1);
}

void	ft_newdirection(t_game *game, int direction)
{
	t_player	*temp;

	temp = game->pl;
	if (game->n_moves < 9999)
	{
		game->n_moves++;
		ft_update_score(game);
	}
	while (temp)
	{
		game->next_dir = direction;
		temp = temp->next;
	}
}
