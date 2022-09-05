/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:06:26 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/05 08:49:31 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"
#include "../inc/utils.h"

void	fullmap_error_check(char **m)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (m[y])
	{
		x = 0;
		while (m[y][x])
		{
			if (!ft_strchr("EGPC10", m[y][x]))
			{
				ft_printf("ERROR\nInvalid character in <map.ber>");
				exit(EXIT_FAILURE);
			}
			x++;
		}
		y++;
	}
}

static void	ft_missing_char(char c)
{
	printf("ERROR\nMissing '%c' character in <map.ber>", c);
	exit(EXIT_FAILURE);
}

void	lay_error_check(t_lay *lay, char **m)
{
	int	y_max;
	int	x_max;
	int	i;

	i = -1;
	y_max = lay->n_row - 1;
	x_max = lay->n_col - 1;
	while (m[++i])
	{
		if ((m[i][0] != '1' || m[i][x_max] != '1') || ((i == 0 || \
						i == y_max) && ft_countchar(m[i], '1') != x_max + 1))
		{
			ft_printf("ERROR\nNot a rectangle or breached map!");
			exit(EXIT_FAILURE);
		}
	}
	if (lay->n_exit == 0)
		ft_missing_char('E');
	if (lay->n_pl == 0)
		ft_missing_char('P');
	if (lay->n_coin == 0)
		ft_missing_char('C');
}
