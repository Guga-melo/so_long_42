/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:11:52 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/10 13:43:06 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/check.h"
#include "mlx.h"

int main(int argc, char **argv)
{
	char	**map;
	t_lay	lay;
	if (argc != 2)
		printf("ERROR: NUMERO DE ARGUMENTO INVALIDO");
	map = check_param(argc, argv, &lay);
}
