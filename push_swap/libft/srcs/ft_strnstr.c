/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kirus <kirus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 00:14:25 by kirus             #+#    #+#             */
/*   Updated: 2021/10/29 20:52:21 by kirus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	ptr1;
	size_t	ptr2;

	ptr1 = 0;
	ptr2 = 0;
	if (*to_find == 0)
		return ((char *)str);
	while (str[ptr1] != '\0' && len > 0)
	{
		while (to_find[ptr2] != '\0' && (to_find[ptr2] == str[ptr1]) && len > 0)
		{
			ptr2++;
			ptr1++;
			len--;
			if (to_find[ptr2] == '\0')
				return ((char *)&str[ptr1 - ptr2]);
		}
		len = len + ptr2 - 1;
		ptr1 = ptr1 - ptr2 + 1;
		ptr2 = 0;
	}
	return (NULL);
}
