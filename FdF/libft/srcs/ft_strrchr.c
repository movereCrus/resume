/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@students.21-school.ru>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 23:23:41 by kirus             #+#    #+#             */
/*   Updated: 2021/10/12 23:23:41 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			i;
	size_t			p;
	char			*str;
	unsigned char	ch;

	str = (char *)s;
	ch = (unsigned char)c;
	p = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ch)
			p = i;
		i++;
		if (str[i] == '\0' && ch == 0)
			p = i;
	}
	if (p == 0 && str[p] != ch)
		return (NULL);
	return (str + p);
}
