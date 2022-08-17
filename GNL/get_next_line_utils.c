/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 09:13:00 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/15 14:42:23 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr_gnl(const char *s, int c)
{
	char	*str;
	char	found;
	int		i;

	str = (char *) s;
	found = (char) c;
	i = 0;
	if (!s)
		return (0);
	while (*str != found)
	{
		if (*str == 0)
			return (0);
		str++;
	}
	return (str);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*result;
	int		j;
	int		i;

	result = malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != 0)
		result[i] = s1[i];
	while (s2[j] != 0)
		result[i++] = s2[j++];
	result[i] = 0;
	free(s1);
	return (result);
}

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
