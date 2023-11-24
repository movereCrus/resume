/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:14:21 by dwarlock          #+#    #+#             */
/*   Updated: 2022/01/03 18:14:53 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

int	checkfmt(char *str, int c)
{
	if (!str)
		return (write(1, "(null)", 6));
	while (*str != 0)
	{
		if (*str == (char)c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_putstr(char *str)
{
	size_t	i;
	size_t	len;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	if (str != 0)
	{
		while (i < len)
		{
			write(1, &str[i], 1);
			i++;
		}
	}
	return (len);
}
