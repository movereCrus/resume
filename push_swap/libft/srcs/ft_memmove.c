/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 19:38:22 by kirus             #+#    #+#             */
/*   Updated: 2021/10/29 21:03:09 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	const unsigned char	*src0;
	unsigned char		*dest0;

	src0 = (const unsigned char *)src;
	dest0 = (unsigned char *)dest;
	if (dest0 == src0)
		return (dest0);
	if (dest0 < src0)
		while (count-- > 0)
			*dest0++ = *src0++;
	else
	{
		src0 = src0 + (count - 1);
		dest0 = dest0 + (count - 1);
		while (count-- > 0)
			*dest0-- = *src0--;
	}
	return (dest);
}
