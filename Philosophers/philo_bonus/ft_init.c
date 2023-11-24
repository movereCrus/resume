/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:50:50 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:02:09 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_create_semaphores(t_simulation *simulation)
{
	sem_unlink("data_race");
	sem_unlink("message");
	sem_unlink("stop");
	sem_unlink("forks");
	sem_unlink("eat_limit");
	simulation->data_race = sem_open("data_race", O_CREAT, 0600, 1);
	simulation->message = sem_open("message", O_CREAT, 0600, 1);
	simulation->stop = sem_open("stop", O_CREAT, 0600, 1);
	simulation->forks = sem_open("forks", O_CREAT, 0600,
			simulation->philo_numbers);
	simulation->eat = sem_open("eat_limit", O_CREAT, 0600, 1);
}

void	ft_destroy_all(t_simulation *simulation, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < simulation->philo_numbers)
		kill(philo[i++].pid, SIGKILL);
	sem_close(simulation->data_race);
	sem_close(simulation->message);
	sem_close(simulation->stop);
	sem_close(simulation->forks);
	sem_close(simulation->eat);
	free(philo);
}

static void	ft_for_each_philo(t_simulation *simulation, t_philo *philo, int i)
{
	philo[i].index = i;
	philo[i].is_dead = NO;
	philo[i].data = simulation;
	philo[i].pid = -1;
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
	simulation->data_race = NULL;
	simulation->stop = NULL;
	simulation->message = NULL;
	simulation->forks = NULL;
	simulation->eat = NULL;
	while (++i < simulation->philo_numbers)
		ft_for_each_philo(simulation, philo, i);
	return (philo);
}

void	ft_print_message(int id, t_philo *philo)
{
	long long	time;

	sem_wait(philo->data->message);
	time = philo->data->time - philo->start;
	if (id == FORK)
		printf("%lld %d has taken a fork\n", time, philo->index + 1);
	else if (id == EATING)
		printf("%lld %d is eating\n", time, philo->index + 1);
	else if (id == SLEEPING)
		printf("%lld %d is sleeping\n", time, philo->index + 1);
	else if (id == THINKING)
		printf("%lld %d is thinking\n", time, philo->index + 1);
	else if (id == DIED)
		printf("%lld %d died\n", time, philo->index + 1);
	if (id != DIED)
		sem_post(philo->data->message);
}
