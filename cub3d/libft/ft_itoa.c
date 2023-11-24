/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:06:14 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 17:07:34 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_digit(int n)
{
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static void	ft_itoa_core(char *dest, int nb, int pos)
{
	pos--;
	if (nb / 10 != 0)
		ft_itoa_core(dest, nb / 10, pos);
	if (nb % 10 < 0)
		dest[pos] = (-(nb % 10)) + '0';
	else
		dest[pos] = nb % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;

	if (n == -2147483648)
	{
		str = ft_strdup("-2147483648");
		return (str);
	}
	if (n >= 0)
	{
		str = malloc(sizeof(char) * (ft_nb_digit(n) + 1));
		if (!str)
			return (NULL);
		ft_itoa_core(str, n, ft_nb_digit(n));
		str[ft_nb_digit(n)] = '\0';
	}
	else
	{
		str = malloc(sizeof(char) * (ft_nb_digit(n) + 2));
		if (!str)
			return (NULL);
		str[0] = '-';
		ft_itoa_core(str, n, ft_nb_digit(n) + 1);
		str[ft_nb_digit(n) + 1] = '\0';
	}
	return (str);
}
/*
int	main(void)
{
	int	n;

	n = 88;
	printf("starting integer %d\n", n);
	printf("itoa char number %s\n", ft_itoa(n));
	return (0);
}
*/