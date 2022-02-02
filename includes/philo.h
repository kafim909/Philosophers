/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:34:12 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/02 15:53:01 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_shared
{
	size_t			die;
	size_t			eat;
	size_t			sleep;
	size_t			nbr_philo;
	size_t			nbr_eat_bool;
	size_t			beg;
	size_t			satiated;
	pthread_mutex_t	write;
	pthread_mutex_t	sat;
	int				finished;
}					t_shared;

typedef struct s_philo
{
	t_shared		*t;
	size_t			is_eating;
	size_t			last_meal;
	pthread_t		id;
	pthread_mutex_t	fork;
	size_t			index;
	void			*first;
}					t_philo;

int		init_mutex(t_philo *ph, int nbr_ph);
int		dead(t_philo *ph, int nbr_philo);
int		ft_isdigit(int c);
int		error_check(int argc, char **argv);
int		eat_process(t_philo *ph, t_philo *nxt);
int		init_struct(t_philo *ph, int nbr_ph, char **argv, int argc);
int		destroy_mutex(t_philo *ph, int nbr_ph);
int		ft_print(int info, t_philo *ph, t_philo *nxt);
size_t	convert(const char *str);
size_t	current_timestamp(size_t beg);
void	sleep_correction(size_t sleeptime);
void	*thread(void *arg);

#endif