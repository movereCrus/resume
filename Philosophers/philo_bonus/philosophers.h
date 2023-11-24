/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:51:05 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:04:12 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <semaphore.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <signal.h>
# include <fcntl.h>

# define YES 1
# define NO 0
# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

typedef struct s_simulation
{
	sem_t			*forks;
	sem_t			*message;
	sem_t			*data_race;
	sem_t			*stop;
	sem_t			*eat;
	long long		time;
	int				philo_numbers;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				eat_counter;
	int				max_eat;
	int				current_eat;
}				t_simulation;

typedef struct s_philo
{
	t_simulation	*data;
	pid_t			pid;
	long long		eating_time;
	long long		next_meal;
	long long		start;
	int				index;
	int				is_dead;
	int				eat_counter;
}				t_philo;

void			ft_usleep(long long time, t_simulation *data);
long long		ft_get_time(void);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			ft_take_fork(t_philo *philo);
void			ft_print_message(int id, t_philo *philo);
t_philo			*ft_philo_init(t_simulation *simulation);
void			ft_create_semaphores(t_simulation *simulation);
int				ft_parsing(char **av, t_simulation *simulation);
void			ft_destroy_all(t_simulation *simulation, t_philo *philo);

#endif
