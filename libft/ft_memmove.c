/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:19:13 by gussoare          #+#    #+#             */
/*   Updated: 2022/05/30 08:21:08 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*str_dst;
	const char	*str_src;

	str_dst = (char *) dst;
	str_src = (char *) src;
	if (len == 0 || str_dst == str_src)
		return (str_dst);
	if (str_dst > str_src)
	{
		while (len--)
			str_dst[len] = str_src[len];
	}
	else
	{
		str_dst = ft_memcpy(str_dst, str_src, len);
	}
	return (str_dst);
}
/*#include <stdio.h>
#include <string.h>

int main(void)
{
	char	dst[50] = "vitoria";
	char	src[50] = "thais";
	size_t	len	= 5;
	printf("%s", ft_memmove(dst, src, len));
	return (0);
}*/
