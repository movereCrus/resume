/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                        :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@students.21-school.ru>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:23:41 by kirus             #+#    #+#             */
/*   Updated: 2021/10/12 23:23:41 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t count)
{
	int		diff;
	size_t	i;

	diff = 0;
	i = 0;
	while (diff == 0 && count != 0 && (str1[i] != '\0' || str2[i] != '\0'))
	{
		diff = (unsigned char)str1[i] - (unsigned char)str2[i];
		i++;
		count--;
	}
	return (diff);
}
