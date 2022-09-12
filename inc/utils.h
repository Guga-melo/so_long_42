/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:22:23 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/12 14:01:59 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "game.h"

char		*ft_strenlarge(char *s1, char *s2);
int			ft_countchar(char *s, int c);
int			ft_strrncmp(char *s1, char *s2, size_t n);
size_t		ft_matrixlen(char **m);
char		**ft_matrixdup(char **m);
void		ft_free_matrix(char ***m);
t_vector	ft_newvector(int x, int y);
int			ft_recursive_power(int nb, int power);
int			ft_sqrt(int nb);
int			ft_euclideandistance(t_vector src, t_vector dest);

#endif
