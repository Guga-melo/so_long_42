/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   legal.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 07:50:47 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/29 10:02:11 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_update_legal(t_game *game, t_player *pl)
{
	pl->legal.north = (!ft_strchr("1G", game->map[pl->pos.y - 1][pl->pos.x]));
	pl->legal.south = (!ft_strchr("1G", game->map[pl->pos.y + 1][pl->pos.x]));
	pl->legal.east = (!ft_strchr("1G", game->map[pl->pos.y][pl->pos.x + 1]));
	pl->legal.west = (!ft_strchr("1G", game->map[pl->pos.y][pl->pos.x - 1]));
}

void	ft_restrict_legal(t_player *ghost)
{
	if (ft_legal_len(ghost) != 1)
	{
		if (ghost->dir == N)
			ghost->legal.south = 0;
		if (ghost->dir == S)
			ghost->legal.north = 0;
		if (ghost->dir == E)
			ghost->legal.west = 0;
		if (ghost->dir == W)
			ghost->legal.east = 0;
	}
}

int	ft_legal_len(t_player *player)
{
	int	count;

	count = 0;
	count += player->legal.north;
	count += player->legal.south;
	count += player->legal.east;
	count += player->legal.west;
	return (count);
}

int	ft_in_legal(t_player *player, int dir)
{
	if (dir == N && player->legal.north)
		return (1);
	if (dir == S && player->legal.south)
		return (1);
	if (dir == E && player->legal.east)
		return (1);
	if (dir == W && player->legal.west)
		return (1);
	if (dir == ST)
		return (1);
	return (0);
}
