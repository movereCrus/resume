/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 00:31:00 by dwarlock          #+#    #+#             */
/*   Updated: 2022/03/05 14:11:57 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_n(char const *s1, char const *s2, size_t len)
{
	char	*news;
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	news = (char *)ft_calloc(ft_strlen(s1) + len + 2, sizeof(char));
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
