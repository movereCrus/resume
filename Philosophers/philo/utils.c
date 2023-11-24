/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:50:40 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:04:44 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_error_put(t_simulation *sim, char *message, int ret)
{
	if (sim)
	{
		if (sim->threads)
			free(sim->threads);
		if (sim->forks)
			free(sim->forks);
	}
	printf("%s\n", message);
	return (ret);
}
