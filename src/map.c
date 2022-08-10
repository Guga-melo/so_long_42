/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:28:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/10 14:31:25 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

char	**ft_read_map(int fd, t_lay *lay, char **map_line)
{
	char	*line;
	char	*last_line;

	line = NULL;
	last_line = NULL;
	while (1)
	{	
		line = get_next_line(fd);
		if (!line)
		{
			if (!lay->n_col)
				printf("ERRO: Mapa vazio");
			else
				ft_check_lay();
		}
	}
}
