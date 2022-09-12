/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:11:52 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/12 14:02:25 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/check.h"
#include "../inc/game.h"

int	main(int argc, char **argv)
{
	char	**map;
	char	**map_check;
	t_lay	lay;

	map = check_param(argc, argv, &lay);
	if (lay.n_pl > 1 || lay.n_exit > 1)
	{
		ft_printf("ERROR\nMore than 1 player or exit");
		return (0);
	}
	map_check = ft_matrixdup(map);
	ft_validate_path(map_check, lay);
	init_game(map, lay);
	return (0);
}
