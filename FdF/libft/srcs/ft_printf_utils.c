/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:33:29 by kirus             #+#    #+#             */
/*   Updated: 2022/03/05 02:49:41 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	checkfmt(char *str, int c)
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

size_t	ft_putstr(char *str)
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
