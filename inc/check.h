/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:36:39 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/17 08:37:59 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define CHECK_H

# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"
# include "utils.h"
# include "map.h"

char	**check_param(int argc, char **argv, t_lay *lay);
char	**check_map(int fd, t_lay *lay);

#endif
