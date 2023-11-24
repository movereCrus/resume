/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radriann <radriann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 17:06:14 by radriann          #+#    #+#             */
/*   Updated: 2022/10/24 17:08:50 by radriann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	res;
	size_t	source;

	res = 0;
	source = 0;
	while (dst[res] && res < dstsize)
		res++;
	while (src[source] && ((res + source + 1) < dstsize))
	{
		dst[res + source] = src[source];
		source++;
	}
	if (res != dstsize)
		dst[res + source] = '\0';
	return (res + ft_strlen(src));
}
