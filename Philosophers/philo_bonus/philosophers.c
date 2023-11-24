/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:51:02 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:01:24 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	*ft_check_death(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->data->data_race);
		philo->data->time = ft_get_time();
		sem_post(philo->data->data_race);
		if (philo->next_meal < philo->data->time)
		{
			sem_wait(philo->data->data_race);
			ft_print_message(DIED, philo);
			sem_post(philo->data->stop);
			break ;
		}
	}
	return (NULL);
}

static void	ft_routine(t_philo *philo)
{
	pthread_t	death;

	sem_wait(philo->data->data_race);
	philo->start = philo->data->time;
	philo->next_meal = philo->start + philo->data->time_to_die;
	sem_post(philo->data->data_race);
	pthread_create(&death, NULL, ft_check_death, philo);
	pthread_detach(death);
	while (1)
	{
		ft_take_fork(philo);
		ft_eat(philo);
		ft_sleep(philo);
		sem_wait(philo->data->data_race);
		ft_print_message(THINKING, philo);
		sem_post(philo->data->data_race);
	}
}

static void	full_philos_checker(t_philo *philo, int number_of_philosophers)
{
	pid_t	_philos_full_checker;
	int		i;

	i = 0;
	if (!philo->data->eat_counter)
		return ;
	_philos_full_checker = fork();
	if (_philos_full_checker)
		return ;
	while (i < number_of_philosophers + 1)
	{
		sem_wait(philo->data->eat);
		i++;
	}
	sem_wait(philo->data->message);
	sem_post(philo->data->stop);
	exit(0);
}

static void	ft_create_process(t_simulation *simulation, t_philo *philo)
{
	int	i;

	i = 0;
	simulation->time = ft_get_time();
	while (i < simulation->philo_numbers)
	{
		if ((i + 1) % 2 == 0)
			philo[i].pid = fork();
		if (philo[i].pid == 0)
			ft_routine(philo + i);
		i++;
	}
	i = 0;
	usleep(250);
	while (i < simulation->philo_numbers)
	{
		if ((i + 1) % 2 != 0)
			philo[i].pid = fork();
		if (philo[i].pid == 0)
			ft_routine(philo + i);
		i++;
	}
	full_philos_checker(philo, simulation->philo_numbers);
}

int	main(int argc, char **argv)
{
	t_simulation	simulation;
	t_philo			*philo;

	if (argc == 5 || argc == 6)
	{
		if (ft_parsing(argv, &simulation))
			return (1);
		philo = ft_philo_init(&simulation);
		ft_create_semaphores(&simulation);
		sem_wait(simulation.stop);
		ft_create_process(&simulation, philo);
		sem_wait(simulation.stop);
		ft_destroy_all(&simulation, philo);
	}
	else
		printf("Usage: [n of philos] [die time] [eat time] [nap time] <n>\n");
	return (0);
}
