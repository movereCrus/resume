/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 14:36:12 by kirus             #+#    #+#             */
/*   Updated: 2022/05/26 16:52:52 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_freeall(char **str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

static char	**ft_strfill(char const *s, char c, char **str, size_t w)
{
	size_t	i;
	size_t	p;

	p = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				str[w][p] = s[i];
				p++;
				i++;
			}
			str[w][p] = '\0';
			p = 0;
			w++;
		}
		else
			i++;
	}
	str[w] = NULL;
	return (str);
}

static char	**ft_wordmalloc(char const *s, char c, char **str, size_t w)
{
	size_t	i;
	size_t	p;

	i = 0;
	while (s[i] != '\0')
	{
		p = 0;
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != '\0')
			{
				p++;
				i++;
			}
			str[w] = (char *)malloc((p + 1) * sizeof(char));
			if (str[w] == NULL)
				return (ft_freeall(str));
			w++;
		}
		else
			i++;
	}
	return (str);
}

static char	**ft_strmalloc(char const *s, char c, size_t w, size_t i)
{
	char	**str;

	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			w++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	str = (char **)malloc((w + 1) * sizeof(char *));
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	w;
	size_t	i;
	char	**str;

	i = 0;
	w = 0;
	if (s == NULL)
		return (NULL);
	str = ft_strmalloc(s, c, w, i);
	if (str == NULL)
		return (NULL);
	str = ft_wordmalloc(s, c, str, w);
	str = ft_strfill(s, c, str, w);
	return (str);
}
