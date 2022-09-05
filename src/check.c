/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:58:48 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/01 09:47:04 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/check.h"

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
		printf("Número de argumentos inválido");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		printf("ERRO: arquivo: %s", argv[1]);
		return (0);
	}
	if (ft_strrncmp(argv[1], ".ber", 4))
	{
		printf("ERRO: tipo de arquivo invalido, use .ber!");
		return (0);
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
		ft_printf("ERRO\nAlocação de memória corrupta");
		exit(EXIT_FAILURE);
	}
	fullmap_error_check(full_map);
	return (full_map);
}
