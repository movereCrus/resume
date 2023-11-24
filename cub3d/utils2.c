/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:06:10 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 16:06:39 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	get_first(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (s1[i])
	{
		flag = 0;
		j = 0 - 1;
		while (set[++j])
		{
			if (set[j] == s1[i])
				flag = 1;
		}
		if (!flag)
			return (i);
		i++;
	}
	return (-1);
}

int	get_last(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && s1[i])
	{
		flag = 0;
		j = 0 - 1;
		while (set[++j])
		{
			if (set[j] == s1[i])
				flag = 1;
		}
		if (!flag)
			return (i);
		i--;
	}
	return (-1);
}

char	*strtrim_back(char const *s1, char const *set)
{
	int		start;
	int		last;
	char	*res;

	if (!s1)
		return (0);
	start = get_first(s1, set);
	last = get_last(s1, set);
	if (start == -1 || last == -1)
	{
		res = (char *)ft_calloc(1, sizeof(char));
		if (!(res))
			return (0);
		return (res);
	}
	res = ft_calloc(last + 2, sizeof(char));
	if (!(res))
		return (0);
	ft_strlcpy(res, s1, last + 2);
	return (res);
}
