/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_pac.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:03:48 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/23 11:36:40 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_player	*ft_murderpath(t_game *game, t_player *ghost)
{
	int			min_dist;
	int			dist;
	t_player	*pacman;
	t_player	*closest;

	pacman = game->pl;
	closest = NULL;
	min_dist = 0;
	while (pacman)
	{
		dist = ft_euclideandistance(ft_newvector(ghost->pos.x, \
				ghost->pos.y), ft_newvector(pacman->pos.x, pacman->pos.y));
		if (!dist || dist < min_dist)
		{
			closest = pacman;
			min_dist = dist;
		}
		pacman = pacman->next;
	}
	return (closest);
}

int	ft_choose_dir(t_game *game, t_player *ghost, t_player *pacman)
{
	int	len;
	int	*distances;

	ft_update_legal(game, ghost);
	ft_restrict_legal(ghost);
	len = ft_legal_len(ghost);
	if (len > 1)
	{
		distances = malloc(5 * sizeof(int));
		if (!distances)
		{
			printf("%sMemory Allocation Error!%s\n", RED, DEFAULT);
			return (end_game(game));
		}
		return (ft_advanced_dir(ghost, pacman, distances));
	}
	if (ghost->legal.north)
		return (N);
	if (ghost->legal.south)
		return (S);
	if (ghost->legal.east)
		return (E);
	if (ghost->legal.west)
		return (W);
	return (ST);
}

int	ft_advanced_dir(t_player *ghost, t_player *pacman, int *distances)
{
	int	i;

	i = 0;
	if (ghost->legal.north)
		distances[i++] = ft_euclideandistance(ft_newvector(ghost->pos.x, \
			ghost->pos.y - 1), ft_newvector(pacman->pos.x, pacman->pos.y));
	else
		distances[i++] = -2;
	if (ghost->legal.south)
		distances[i++] = ft_euclideandistance(ft_newvector(ghost->pos.x, \
			ghost->pos.y + 1), ft_newvector(pacman->pos.x, pacman->pos.y));
	else
		distances[i++] = -2;
	if (ghost->legal.east)
		distances[i++] = ft_euclideandistance(ft_newvector(ghost->pos.x + 1, \
			ghost->pos.y), ft_newvector(pacman->pos.x, pacman->pos.y));
	else
		distances[i++] = -2;
	if (ghost->legal.west)
		distances[i++] = ft_euclideandistance(ft_newvector(ghost->pos.x - 1, \
			ghost->pos.y), ft_newvector(pacman->pos.x, pacman->pos.y));
	else
		distances[i++] = -2;
	distances[i] = -1;
	return (ft_advanced_dir2(distances));
}

int	ft_advanced_dir2(int *distances)
{
	int	min;
	int	i;
	int	j;

	i = -1;
	j = 0;
	min = -1;
	while (distances[++i] != -1)
	{
		if (distances[i] >= 0 && (min == -1 || distances[i] < min))
		{
			min = distances[i];
			j = i;
		}
	}
	free(distances);
	if (j == 0)
		return (N);
	if (j == 1)
		return (S);
	if (j == 2)
		return (E);
	if (j == 3)
		return (W);
	return (ST);
}

int	ft_find_ghost(t_player *pl, t_vector pos)
{
	t_player	*gh;

	gh = pl;
	while (gh)
	{
		if (gh->pos.x == pos.x && gh->pos.y == pos.y)
			return (1);
		gh = gh->next;
	}
	return (0);
}
