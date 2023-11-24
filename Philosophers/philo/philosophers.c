/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:50:14 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:05:41 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_check_death(t_philo *philo)
{
	while (!philo->data->is_fed)
	{
		philo->data->time = ft_get_time();
		if (philo->next_meal < philo->data->time)
		{
			philo->data->is_dead = YES;
			ft_print_message(DIED, philo);
			break ;
		}
	}
	pthread_mutex_unlock(philo->data->stop);
	return (NULL);
}

static int	ft_check_eat(t_philo *philo)
{
	if ((philo->data->eat_counter != -1)
		&& (philo->data->current_eat >= philo->data->max_eat))
	{
		philo->data->is_fed = YES;
		pthread_mutex_lock(philo->eat);
		return (0);
	}
	return (1);
}

static void	*ft_routine(void *arg)
{
	t_philo		*philo;

	philo = arg;
	philo->start = philo->data->time;
	philo->next_meal = philo->start + philo->data->time_to_die;
	while (!philo->data->is_dead && !philo->data->is_fed)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		if (!ft_check_eat(philo))
			break ;
		ft_sleep(philo);
		ft_print_message(THINKING, philo);
	}
	return (NULL);
}

static void	ft_create_threads(t_simulation *sim, t_philo *philo)
{
	int		i;

	i = 0;
	while (i < sim->philo_numbers)
	{
		if ((i + 1) % 2 == 0)
		{
			pthread_create(sim->threads + i, NULL, ft_routine, philo + i);
			pthread_detach(sim->threads[i++]);
		}
		i++;
	}
	i = 0;
	usleep(250);
	while (i < sim->philo_numbers)
	{
		if ((i + 1) % 2 != 0)
		{
			pthread_create(sim->threads + i, NULL, ft_routine, philo + i);
			pthread_detach(sim->threads[i++]);
		}
		i++;
	}
	ft_check_death(philo);
	pthread_mutex_unlock(philo->data->stop);
}

int	main(int argc, char **argv)
{
	t_simulation	sim;
	t_philo			*philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_parsing(argv, &sim))
			return (0);
		philo = ft_philo_init(&sim);
		sim.time = ft_get_time();
		ft_create_mutex(&sim);
		pthread_mutex_lock(sim.stop);
		ft_create_threads(&sim, philo);
		pthread_mutex_lock(sim.stop);
		ft_destroy_all(&sim, philo);
	}
	else
		printf("Usage: [n of philos] [die time] [eat time] [nap time] <n>\n");
	return (0);
}
