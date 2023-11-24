/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbrs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 00:33:37 by kirus             #+#    #+#             */
/*   Updated: 2022/03/05 19:25:34 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	putnbr_p(size_t nb, char *line)
{
	size_t	len;
	int		i;
	char	str[20];

	i = 0;
	len = 0;
	if (nb == 0)
		return (write(1, line, 1));
	while (nb != 0)
	{
		str[i++] = line[nb % 16];
		nb /= 16;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}

size_t	putnbr_uhex(unsigned int nb, char *line, int base)
{
	size_t	len;
	int		i;
	char	str[10];

	i = 0;
	len = 0;
	if (nb == 0)
		return (write(1, line, 1));
	while (nb != 0)
	{
		str[i++] = line[nb % base];
		nb /= base;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}

size_t	putnbr_d(long nb, char *line)
{
	size_t	len;
	int		i;
	char	str[10];

	i = 0;
	len = 0;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
		len++;
	}
	if (nb == 0)
		return (write(1, line, 1));
	while (nb != 0)
	{
		str[i++] = line[nb % 10];
		nb /= 10;
		len++;
	}
	while (i--)
		write(1, &str[i], 1);
	return (len);
}
