/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 13:39:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/18 14:22:03 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/game.h"

t_list	*load_pac_death(t_game *game)
{
	t_list *pacdeath;
	char	*s;
	int		c;
	int		size;

	pacdeath = NULL;
	s = ft_substr("../sprites/Pac-Man/Dying/pacman_dying1.xpm", 0, 42);
	c = '0';
	while (c++ < '9')
	{
		ft_memset(&s[37], c, 1);
		ft_lstadd_back(&pacdeath, \
				ft_lstnew(mlx_xpm_file_to_image(game->id, s, &size, &size)));
	}
	free(s);
	while (c-- > '7')
	{
		ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(game->id, \
				"../sprites/Other/Walls/black.xpm", &size, &size)));
		ft_lstadd_back(&pacdeath, ft_lstnew(mlx_xpm_file_to_image(game->id, \
				"../sprites/Pac-Man/Dying/pacman_woosh.xpm", &size, &size)));
	}
	return (pacdeath);
}
