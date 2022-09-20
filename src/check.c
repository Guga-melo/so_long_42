/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:58:48 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/14 12:40:57 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/check.h"

int	ft_check_exit(char **map, int x, int y)
{
	if (map[y][x + 1] == 'P')
		return (1);
	else if (map[y][x - 1] == 'P')
		return (1);
	else if (map[y + 1][x] == 'P')
		return (1);
	else if (map[y - 1][x] == 'P')
		return (1);
	else
		return (0);
}

t_lay	ft_new_lay(void)
{
	t_lay	lay;

	lay.n_row = 0;
	lay.n_col = 0;
	lay.n_exit = 0;
	lay.n_pl = 0;
	lay.n_coin = 0;
	return (lay);
}

char	**check_param(int argc, char **argv, t_lay *lay)
{
	int	fd;

	if (argc != 2)
	{
		ft_printf("ERROR\nInvalid number of arguments");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("ERROR\nFile do not open or exist: %s", argv[1]);
		exit(EXIT_FAILURE);
	}
	if (ft_strrncmp(argv[1], ".ber", 4))
	{
		ft_printf("ERROR\nWrong file type, use .ber!");
		exit(EXIT_FAILURE);
	}
	return (check_map(fd, lay));
}

char	**check_map(int fd, t_lay *lay)
{
	char	*map_line;
	char	**full_map;

	map_line = NULL;
	full_map = NULL;
	*lay = ft_new_lay();
	ft_read_map(fd, lay, &map_line);
	full_map = ft_split(map_line, '\n');
	lay_error_check(lay, full_map);
	free(map_line);
	if (!full_map)
	{
		ft_printf("ERROR\nFull_map was not allocated correctly");
		exit(EXIT_FAILURE);
	}
	fullmap_error_check(full_map);
	return (full_map);
}
