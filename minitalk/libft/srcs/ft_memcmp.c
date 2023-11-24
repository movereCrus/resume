/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:23:41 by kirus             #+#    #+#             */
/*   Updated: 2021/10/12 23:38:45 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t count)
{
	int				diff;
	size_t			i;
	unsigned char	*str01;
	unsigned char	*str02;

	diff = 0;
	i = 0;
	str01 = (unsigned char *)str1;
	str02 = (unsigned char *)str2;
	while (diff == 0 && count != 0)
	{
		diff = str01[i] - str02[i];
		i++;
		count--;
	}
	return (diff);
}
