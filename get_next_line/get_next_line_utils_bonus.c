/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:30:52 by dwarlock          #+#    #+#             */
/*   Updated: 2021/12/28 00:40:49 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*news;
	size_t	i;

	i = 0;
	news = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (news == NULL)
		return (NULL);
	while (*s1 != '\0')
		news[i++] = *s1++;
	while (*s2 != '\0')
		news[i++] = *s2++;
	news[i] = '\0';
	return (news);
}

char	*ft_strjoin_n(char const *s1, char const *s2, size_t len)
{
	char	*news;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	news = (char *)malloc(ft_strlen(s1) + len + 2);
	if (news == NULL)
		return (NULL);
	while (*s1 != '\0')
		news[i++] = *s1++;
	while (s2[j] != '\0' && j <= len)
	{
		news[i++] = s2[j++];
		if (s2[j - 1] == '\n')
			break ;
	}
	news[i] = '\0';
	return (news);
}
