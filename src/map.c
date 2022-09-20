/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 11:28:37 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/14 12:46:38 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"
#include "../inc/map.h"
#include "../inc/check.h"

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
				ft_printf("ERROR\nEmpty map");
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

int	ft_infest(char	**map, int x, int y)
{
	if (ft_strchr("0C", map[y][x + 1]))
		map[y][x + 1] = 'P';
	else if (ft_strchr("0C", map[y][x - 1]))
		map[y][x - 1] = 'P';
	else if (ft_strchr("0C", map[y + 1][x]))
		map[y + 1][x] = 'P';
	else if (ft_strchr("0C", map[y - 1][x]))
		map[y - 1][x] = 'P';
	return (1);
}

void	ft_validate_path(char **map, t_lay lay)
{
	int	x;
	int	y;
	int	count;

	count = lay.n_row * 2;
	while (count--)
	{
		y = 0;
		while (map[y])
		{
			x = 0;
			while (map[y][x])
			{
				if (map[y][x] == 'P')
					ft_infest(map, x, y);
				x++;
			}
			y++;
		}
		y = 0;
	}
	ft_validate_path2(map);
}

void	ft_validate_path2(char **map)
{
	int	x;
	int	y;
	int	valid;

	valid = 2;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'E')
				valid = ft_check_exit(map, x, y);
			if (map[y][x] == 'C')
				valid = 0;
			if (valid == 0)
				break ;
			x++;
		}
		y++;
	}
	path_error_check(valid);
}
