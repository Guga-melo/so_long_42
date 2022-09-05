/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:28:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/01 09:17:44 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/map.h"
#include <stdio.h>

void	ft_read_map(int fd, t_lay *lay, char **map_line)
{
	char	*line;

	line = NULL;
	while (1)
	{	
		line = get_next_line(fd);
		if (!line)
		{
			if (!lay->n_col)
			{
				ft_printf("ERRO: Mapa vazio");
				exit(EXIT_FAILURE);
			}
			break ;
		}
		ft_check_lay(line, lay);
		*map_line = ft_strenlarge(*map_line, line);
		lay->n_row++;
	}
}

void	ft_check_lay(char *line, t_lay *lay)
{
	if (!lay->n_col)
		lay->n_col = ft_strlen(line) - 1;
	lay->n_exit += ft_countchar(line, 'E');
	lay->n_pl += ft_countchar(line, 'P');
	lay->n_coin += ft_countchar(line, 'C');
}
