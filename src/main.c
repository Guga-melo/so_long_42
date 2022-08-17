/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:11:52 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/17 09:07:53 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "../inc/check.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	char	**map;
	t_lay	lay;
	map = check_param(argc, argv, &lay);
	if (!map)
	{
		printf("\nERRO: map vazio: main");
		return (0);
	}
	int i = -1;
	while (map[++i])
		printf("%s\n", map[i]);
	return (0);
}
