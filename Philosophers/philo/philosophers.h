/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 16:50:18 by dwarlock          #+#    #+#             */
/*   Updated: 2022/06/28 17:08:24 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

# define YES 1
# define NO 0
# define FORK 1
# define EATING 2
# define SLEEPING 3
# define THINKING 4
# define DIED 5

typedef struct s_simulation
{
	pthread_t			*threads;
	pthread_mutex_t		*forks;
	pthread_mutex_t		*message;
	pthread_mutex_t		*death;
	pthread_mutex_t		*stop;
	long long			time;
	int					philo_numbers;
	long long			time_to_die;
	long long			time_to_eat;
	long long			time_to_sleep;
	int					eat_counter;
	int					max_eat;
	int					is_dead;
	int					is_fed;
	int					current_eat;
}				t_simulation;

typedef struct s_philo
{
	pthread_mutex_t	*eat;
	t_simulation	*data;
	long long		start;
	long long		eating_time;
	long long		next_meal;
	int				index;
	int				right_hand;
	int				left_hand;
	int				eat_counter;
}				t_philo;

void			ft_usleep(long long time, t_simulation *data);
long long		ft_get_time(void);
void			ft_eat(t_philo *philo);
void			ft_sleep(t_philo *philo);
void			ft_take_fork(t_philo *philo);
void			ft_print_message(int id, t_philo *philo);
t_philo			*ft_philo_init(t_simulation *simulation);
void			ft_create_mutex(t_simulation *simulation);
int				ft_parsing(char **av, t_simulation *simulation);
void			ft_destroy_all(t_simulation *simulation, t_philo *philo);
int				ft_error_put(t_simulation *simulation, char *message, int ret);

#endif
