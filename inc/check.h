/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 13:36:39 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/10 14:27:22 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK_H
# define Check_H

# include "fcntl.h"
# include "../libft/libft.h"
# include "map.h"

t_lay	ft_new_lay(void);
char	**check_param(int argc, char **argv, t_lay *lay);
char	**check_map(int fd, t_lay *lay);

#endif
