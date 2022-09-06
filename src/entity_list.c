/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 08:22:34 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/05 10:34:39 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

void	ft_entitylist(char **map, t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				ft_entadd_back(&game->pl, ft_entnew(ft_newvector(x, y)));
			x++;
		}
		y++;
	}
}

int	ft_deletefirst_ent(t_game *game)
{
	t_player	*head;

	head = game->pl;
	if (head->next)
		game->pl = head->next;
	else
		game->pl = NULL;
	free(head);
	head = NULL;
	return (1);
}

int	ft_deletelast_ent(t_game *game)
{
	t_player	*head;

	head = game->pl;
	while (head->next->next)
		head = head->next;
	free(head->next);
	head->next = NULL;
	return (1);
}

void	free_entitylist(t_game *game)
{
	t_player	*temp;

	while (game->pl)
	{
		temp = game->pl;
		game->pl = game->pl->next;
		free(temp);
		temp = NULL;
	}
}
