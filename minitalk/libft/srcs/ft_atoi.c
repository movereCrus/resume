/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 14:56:08 by kirus             #+#    #+#             */
/*   Updated: 2022/02/15 17:25:20 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX 922337203685477580

static size_t	ft_evnumber(size_t neg, const char *str)
{
	size_t	num0;
	size_t	i;

	i = 0;
	num0 = 0;
	while (*str > 47 && *str < 58)
	{
		if ((i > 17) && ((*str - 48 >= 7 && num0 == MAX) || num0 > MAX))
		{
			if (neg > 0)
				return (0);
			return (-1);
		}
		num0 = num0 * 10 + *str - 48;
		str++;
		i++;
	}
	if (neg > 0)
		num0 = -num0;
	return (num0);
}

int	ft_atoi(const char *str)
{
	size_t	neg;

	neg = 0;
	while ((*str < 14 && *str > 8) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg++;
		str++;
	}
	if (*str > 47 && *str < 58)
		neg = ft_evnumber(neg, str);
	else
		neg = 0;
	return ((int)neg);
}
