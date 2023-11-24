/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 16:46:56 by kirus             #+#    #+#             */
/*   Updated: 2021/10/17 23:20:11 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	news = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (news == NULL)
		return (NULL);
	while (*s1 != '\0')
	{
		news[i] = *s1;
		i++;
		s1++;
	}
	while (*s2 != '\0')
	{
		news[i] = *s2;
		i++;
		s2++;
	}
	news[i] = '\0';
	return (news);
}
