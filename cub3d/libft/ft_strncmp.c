/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:06:14 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 17:09:56 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	i = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n-- != 0)
	{
		if (str1[i] != str2[i] || str1[i] == 0 || str2[i] == 0)
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
