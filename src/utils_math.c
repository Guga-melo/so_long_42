/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gussoare <gussoare@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:27:21 by gussoare          #+#    #+#             */
/*   Updated: 2022/08/23 07:39:23 by gussoare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/utils.h"

int	ft_sqrt(int nb)
{
	int	i;

	i = 0;
	if (nb * nb <= 2147483647)
	{
		while (i * i < nb)
		{
			i++;
			if (i * i > nb)
				return (i - 1);
		}
	}
	return (i);
}

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (0);
	while (power > 1)
	{
		power--;
		nb *= ft_recursive_power(nb, power);
	}
	return (nb);
}

int	ft_euclideandistance(t_vector src, t_vector dest)
{
	return (ft_sqrt(ft_recursive_power(dest.x - src.x, 2) + \
				ft_recursive_power(dest.y - src.y, 2)));
}

int main()
{
	printf("%d", ft_sqrt(144));
	return (0);
}

