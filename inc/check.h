/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:36:39 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/12 14:06:39 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <fcntl.h>
# include "../libft/libft.h"
# include "utils.h"
# include "map.h"

char	**check_param(int argc, char **argv, t_lay *lay);
char	**check_map(int fd, t_lay *lay);
int		ft_check_exit(char **map, int x, int y);

#endif
