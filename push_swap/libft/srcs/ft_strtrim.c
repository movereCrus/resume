/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 23:08:11 by kirus             #+#    #+#             */
/*   Updated: 2021/10/17 23:20:39 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_bos(char const *s1, char const *set)
{
	size_t	bos;
	size_t	eos;
	size_t	i;

	i = 0;
	bos = 0;
	eos = ft_strlen(s1) - 1;
	while (bos < eos)
	{
		while ((s1[bos] != set[i]) && set[i] != '\0')
			i++;
		if (i == ft_strlen(set))
			break ;
		bos++;
		i = 0;
	}
	return (bos);
}

static	int	ft_eos(char const *s1, char const *set, size_t bos)
{
	size_t	eos;
	size_t	i;

	i = 0;
	eos = ft_strlen(s1) - 1;
	while (eos >= bos)
	{
		while ((s1[eos] != set[i]) && set[i] != '\0')
			i++;
		if (i == ft_strlen(set))
			break ;
		eos--;
		i = 0;
	}
	return (eos);
}

char	*ft_mallcpy(size_t eos, size_t bos, char const *s1)
{
	size_t	i;
	char	*s10;

	s10 = (char *)malloc((eos - bos + 2) * sizeof(char));
	if (s10 == NULL)
		return (NULL);
	i = 0;
	while (bos <= eos)
	{
		s10[i] = s1[bos];
		i++;
		bos++;
	}
	s10[i] = '\0';
	return (s10);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	bos;
	size_t	eos;

	if (s1 == NULL || set == NULL)
		return (NULL);
	if (ft_strlen(s1) == 0 || (ft_strlen(s1) == 1 && (*s1 == *set)))
		return (ft_strdup(""));
	bos = ft_bos(s1, set);
	eos = ft_eos(s1, set, bos);
	if (eos < bos)
		return (ft_strdup(""));
	return (ft_mallcpy(eos, bos, s1));
}
