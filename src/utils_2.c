/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 09:26:31 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/05 08:18:56 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

size_t	ft_matrixlen(char **m)
{
	size_t	r;
	size_t	i;

	r = 0;
	i = -1;
	while (m[++i])
		r++;
	return (r);
}

void	ft_free_matrix(char ***m)
{
	int	i;

	i = 0;
	while (m && m[0] && m[0][i])
	{
		free(m[0][i]);
		i++;
	}
	if (m)
	{
		free(m[0]);
		*m = NULL;
	}
}

char	**ft_matrixdup(char **m)
{
	char	**dup;
	int		n_row;
	int		i;

	i = 0;
	n_row = ft_matrixlen(m);
	dup = malloc((n_row + 1) * sizeof(char *));
	while (m[i])
	{
		dup[i] = ft_strdup(m[i]);
		if (!dup[i])
		{
			ft_free_matrix(&dup);
			return (0);
		}
		i++;
	}
	dup[i] = 0;
	return (dup);
}

t_vector	ft_newvector(int x, int y)
{
	t_vector	position;

	position.x = x;
	position.y = y;
	return (position);
}
