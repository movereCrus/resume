/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 15:26:25 by kirus             #+#    #+#             */
/*   Updated: 2021/10/29 20:40:13 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t			i;
	char			*str;
	unsigned char	ch;

	str = (char *)s;
	ch = (unsigned char)c;
	i = 0;
	while (str[i] != ch && str[i] != '\0')
		i++;
	if (str[i] == '\0' && ch != 0)
		return (NULL);
	return (str + i);
}
