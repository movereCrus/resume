/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 23:11:16 by kirus             #+#    #+#             */
/*   Updated: 2021/10/25 01:49:34 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	eos;
	size_t	ctr;

	eos = 0;
	ctr = 0;
	while (dest[eos] != '\0' && eos < size)
		eos++;
	while ((eos + ctr + 1) < size && src[ctr] != '\0')
	{
		dest[eos + ctr] = src[ctr];
		ctr++;
	}
	if (eos < size)
		dest[eos + ctr] = '\0';
	return (eos + ft_strlen(src));
}
