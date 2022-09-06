/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:11:52 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/06 09:51:50 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/check.h"
#include "../inc/game.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	char	**map;
	t_lay	lay;

	map = check_param(argc, argv, &lay);
	init_game(map, lay);
	return (0);
}
