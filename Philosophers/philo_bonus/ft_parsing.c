/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:50:54 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:01:52 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	ft_error_put(char *message, int ret)
{
	printf("%s\n", message);
	return (ret);
}

static int	ft_set_rest(t_simulation *simulation, long long num, int i)
{
	if (i == 4)
	{
		if (num < 60)
			return (ft_error_put("Error: time to sleep should be >=60ms", 1));
		simulation->time_to_sleep = num;
	}
	else if (i == 5)
	{
		if (num == 0)
			simulation->eat_counter = -1;
		else
		{
			simulation->eat_counter = num;
			simulation->current_eat = 0;
			simulation->max_eat = num * simulation->philo_numbers;
		}
	}
	return (0);
}

static int	ft_set_data(t_simulation *simulation, long long num, int i)
{
	if (i == 1)
	{
		if (num == 0)
			return (ft_error_put("Error: number of philos can't be null", 1));
		simulation->philo_numbers = num;
	}
	else if (i == 2)
	{
		if (num < 60)
			return (ft_error_put("Error: time to die should be >=60ms", 1));
		simulation->time_to_die = num;
	}
	else if (i == 3)
	{
		if (num < 60)
			return (ft_error_put("Error: time to eat should be >=60ms", 1));
		simulation->time_to_eat = num;
	}
	else if (ft_set_rest(simulation, num, i))
		return (1);
	return (0);
}

static long long	ft_get_number(char *arg)
{
	int			i;
	long long	num;

	i = 0;
	num = 0;
	while (arg[i])
	{
		if (arg[i] >= '0' && arg[i] <= '9')
			num = num * 10 + (arg[i] - '0');
		else
			return (ft_error_put("Error: Incorrect characters", -1));
		i++;
	}
	return (num);
}

int	ft_parsing(char **argv, t_simulation *simulation)
{
	long long		num;
	int				i;

	i = 1;
	while (argv[i])
	{
		num = ft_get_number(argv[i]);
		if (num == -1)
			return (1);
		if (ft_set_data(simulation, num, i))
			return (1);
		i++;
	}
	if (i == 5)
	{
		simulation->eat_counter = -1;
		simulation->current_eat = -1;
		simulation->max_eat = -1;
	}
	return (0);
}
