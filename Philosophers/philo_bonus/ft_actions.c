/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:50:45 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 16:50:46 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec * 1000) + (current_time.tv_usec / 1000));
}

void	ft_usleep(long long time, t_simulation *data)
{
	long long	start;

	start = data->time + time;
	while (data->time < start)
		usleep(250);
}

void	ft_take_fork(t_philo *philo)
{
	sem_wait(philo->data->forks);
	sem_wait(philo->data->forks);
	sem_wait(philo->data->data_race);
	ft_print_message(FORK, philo);
	ft_print_message(FORK, philo);
	sem_post(philo->data->data_race);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->data->data_race);
	ft_print_message(EATING, philo);
	sem_post(philo->data->data_race);
	philo->next_meal = philo->data->time
		+ philo->data->time_to_die;
	ft_usleep(philo->data->time_to_eat, philo->data);
	if (philo->data->eat_counter != -1)
	{
		philo->data->current_eat++;
		if (philo->data->eat_counter == philo->data->current_eat)
			sem_post(philo->data->eat);
	}
	sem_post(philo->data->forks);
	sem_post(philo->data->forks);
}

void	ft_sleep(t_philo *philo)
{
	sem_wait(philo->data->data_race);
	ft_print_message(SLEEPING, philo);
	sem_post(philo->data->data_race);
	ft_usleep(philo->data->time_to_sleep, philo->data);
}
