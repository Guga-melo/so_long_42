/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 08:41:41 by gussoare          #+#    #+#             */
/*   Updated: 2022/09/06 14:11:21 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (!(s[i] == c))
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static size_t	ft_strsize(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != 0 && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	if (!s)
		return (0);
	str = malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (str == 0)
		return (0);
	while (s[j] != 0 && i < ft_wordcount(s, c))
	{
		while (s[j] == c)
			j++;
		str[i] = ft_substr(&s[j], 0, ft_strsize(&s[j], c));
		j += ft_strsize(&s[j], c);
		i++;
	}
	str[i] = 0;
	return (str);
}

/*#include <stdio.h>

int main()
{
	char	**str;
	size_t	i;

	i = 0;
	str = ft_split("guga,buga,tuca,buga", ',');
	while (str[i])	
		printf("%s\n", str[i++]);
	return (0);
}*/
