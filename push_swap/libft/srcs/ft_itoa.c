/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:00:48 by kirus             #+#    #+#             */
/*   Updated: 2021/10/29 19:45:50 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_conv(char *str, int n, int l)
{
	int	t;

	if (n < 0)
	{
		l++;
		t = -n;
	}
	else
		t = n;
	str[l--] = '\0';
	while (t > 0)
	{
		str[l--] = (t % 10) + 48;
		t /= 10;
	}
	if (n < 0)
		str[l] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int		t;
	int		l;
	char	*str;

	l = 0;
	t = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
		t = -n;
	while (t > 0)
	{
		t /= 10;
		l++;
	}
	if (n > 0)
		str = (char *)malloc((l + 1) * sizeof(char));
	else
		str = (char *)malloc((l + 2) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_conv(str, n, l);
	return (str);
}
