/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 08:14:49 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/31 14:37:29 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

char	*ft_strenlarge(char *s1, char *s2)
{
	char	*result;
	int		j;
	int		i;

	if (!s2)
		return (0);
	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (result == 0)
		return (0);
	i = -1;
	j = 0;
	while (s1[++i] != 0)
		result[i + j] = s1[i];
	while (s2[j] != 0)
	{
		result[i + j] = s2[j];
		j++;
	}
	result[i + j] = 0;
	free(s1);
	free(s2);
	return (result);
}

int	ft_countchar(char *s, int c)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			count++;
		s++;
	}
	return (count);
}

int	ft_strrncmp(char *s1, char *s2, size_t n)
{
	int	len1;
	int	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if (n == 0)
		return (0);
	while (n--)
	{
		if (s1[len1] != s2[len2])
			return (s1[len1] - s2[len2]);
		len1--;
		len2--;
	}
	return (0);
}
