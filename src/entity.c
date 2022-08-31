/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 08:36:06 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/31 13:06:55 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_player	*ft_entnew(t_vector pos)
{
	t_player *player;

	player = malloc(sizeof(t_player));
	if (!player)
		return (NULL);
	player->pos = pos;
	player->win_pos = ft_newvector(pos.x * SIZE, pos.y * SIZE);
	player->moving = 0;
	player->next = NULL;
	return (player);
}

void	ft_entadd_back(t_player **lst, t_player *newnode)
{
	t_player	*start;

	start = *lst;
	if (*lst)
	{
		while (start->next)
			start = start->next;
		start->next = newnode;
	}
	else
		*lst = newnode;
}

int	ft_delete_entity(t_game *game, t_vector old)
{
	t_player	*temp;
	t_player	*prev;

	temp = game->pl;
	prev = NULL;
	game->lay->n_pl--;
	while (temp)
	{
		if (temp->pos.x == old.x && temp->pos.y == old.y)
		{
			ft_free_singlepl(game, temp);
			if (!prev)
				return (ft_deletefirst_ent(game));
			if (prev && !temp->next)
				return (ft_deletelast_ent(game));
			prev->next = temp->next;
			free(temp);
			temp = NULL;
			return (1);
		}
		prev = temp;
		temp = temp->next;
	}
	return (1);
}

int	ft_update(t_game *game)
{
	int		x;
	int		y;

	y = 0;

	game->n_frames++;
	ft_check_game(game);
	if (game->redraw)
	{
		mlx_put_image_to_window(game->id, game->w_id, game->sprites.logo, \
		(game->width - 131) / 2, game->height - 42);
		ft_update_score(game);
		while (game->map[y])
		{
			x = 0;
			while (game->map[y][x])
			{
				ft_put_map(game, x, y);
				x++;
			}
			y++;
		}
		game->redraw = 0;
	}
	return (0);
}
