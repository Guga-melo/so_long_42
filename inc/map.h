/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 08:21:20 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/10 14:31:20 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include "../GNL/get_next_line.h"

typedef struct	s_lay
{
	int			n_row;
	int			n_col;
	int			n_exit;
	int			n_pl;
	int			n_en;
	int			n_coin;
}							t_lay;

t_lay	ft_new_lay(void);

char	ft_read_map(int fd, t_lay *lay, char **map_line);



#endif

