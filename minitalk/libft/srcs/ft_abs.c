/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 14:30:34 by kirus             #+#    #+#             */
/*   Updated: 2022/03/05 19:42:43 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_abs(long num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
