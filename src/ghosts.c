/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ghosts.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 09:52:06 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/22 14:36:53 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_list	*ft_chooseghcolor(t_game *game, int i, int dir)
{
	t_list	*anim;
	char	*s;
	int		j;

	j = 0;
	anim = NULL;
	s = NULL;
	s = ft_substr("../sprites/Ghosts/R/", 0, 20);
	if (i > 0)
		ft_memset(&s[15], COLORS[i % 7], 1);
	if (dir == N)
		anim = ft_load_north(game, s, j);
	if (dir == S)
		anim = ft_load_south(game, s, j);
	if (dir == E)
		anim = ft_load_east(game, s, j);
	if (dir == W)
		anim = ft_load_west(game, s, j);
	free(s);
	return (anim);
}

void	ft_load_ghosts(t_game *game)
{
	t_player	*ghost;
	int			i;

	i = 0;
	ghost = game->gh;
	while (ghost)
	{
		ghost->sprites.up = ft_chooseghcolor(game, i, N);
		ghost->sprites.up_bak = ghost->sprites.up;
		ghost->sprites.down = ft_chooseghcolor(game, i, S);
		ghost->sprites.down_bak = ghost->sprites.down;
		ghost->sprites.right = ft_chooseghcolor(game, i, E);
		ghost->sprites.right_bak = ghost->sprites.right;
		ghost->sprites.left = ft_chooseghcolor(game, i, W);
		ghost->sprites.left_bak = ghost->sprites.left;
		ghost->sprites.panic = ft_load_panic(game, i);
		ghost->sprites.panic_bak = ghost->sprites.panic;
		ghost = ghost->next;
		i++;
	}
}

void	ft_update_ghosts(t_game *game)
{
	t_palyer	*ghost;
	t_player	*closest;
	int dir;
	ghost = game->gh;
	while (ghost && !ghost->moving)
	{
		closest = ft_murderpath(game, ghost);
	}
}
