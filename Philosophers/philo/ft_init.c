/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:50:00 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:07:22 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_create_mutex(t_simulation *simulation)
{
	int	i;

	i = 0;
	pthread_mutex_init(simulation->message, NULL);
	pthread_mutex_init(simulation->death, NULL);
	pthread_mutex_init(simulation->stop, NULL);
	while (i < simulation->philo_numbers)
		pthread_mutex_init(simulation->forks + i++, NULL);
}

void	ft_destroy_all(t_simulation *simulation, t_philo *philo)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(simulation->death);
	pthread_mutex_destroy(simulation->message);
	pthread_mutex_destroy(simulation->stop);
	while (i < simulation->philo_numbers)
	{
		pthread_mutex_destroy(simulation->forks + i);
		pthread_mutex_destroy(philo[i].eat);
		free(philo[i].eat);
		i++;
	}
	free(philo);
	free(simulation->forks);
	free(simulation->threads);
	free(simulation->death);
	free(simulation->message);
	free(simulation->stop);
}

static void	ft_for_each_philo(t_simulation *simulation, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].left_hand = i;
	philo[i].right_hand = (i + 1) % simulation->philo_numbers;
	philo[i].data = simulation;
	philo[i].eat = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo[i].eat, NULL);
	if (simulation->eat_counter == -1)
		philo[i].eat_counter = -1;
	else
		philo[i].eat_counter = simulation->eat_counter;
}

t_philo	*ft_philo_init(t_simulation *simulation)
{
	t_philo	*philo;
	int		i;

	i = -1;
	philo = malloc(sizeof(t_philo) * simulation->philo_numbers);
	simulation->stop = malloc(sizeof(pthread_mutex_t));
	simulation->death = malloc(sizeof(pthread_mutex_t));
	simulation->message = malloc(sizeof(pthread_mutex_t));
	while (++i < simulation->philo_numbers)
		ft_for_each_philo(simulation, philo, i);
	return (philo);
}

void	ft_print_message(int id, t_philo *philo)
{
	long long	time;

	pthread_mutex_lock(philo->data->message);
	time = philo->data->time - philo->start;
	if (id == FORK && !philo->data->is_dead && !philo->data->is_fed)
		printf("%lld %d has taken a fork\n", time, philo->index + 1);
	else if (id == EATING && !philo->data->is_dead && !philo->data->is_fed)
		printf("%lld %d is eating\n", time, philo->index + 1);
	else if (id == SLEEPING && !philo->data->is_dead && !philo->data->is_fed)
		printf("%lld %d is sleeping\n", time, philo->index + 1);
	else if (id == THINKING && !philo->data->is_dead && !philo->data->is_fed)
		printf("%lld %d is thinking\n", time, philo->index + 1);
	else if (id == DIED)
		printf("%lld %d died\n", time, philo->index + 1);
	if (id != DIED)
		pthread_mutex_unlock(philo->data->message);
}
