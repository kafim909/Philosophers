/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 15:30:35 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/04 13:17:22 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	philo_1(t_philo *ph)
{
	pthread_mutex_lock(&ph->t->write);
	printf("[%8zu] PHILO 1 IS DEAD\n", ph->t->die);
	ph->t->finished = 1;
	pthread_mutex_unlock(&ph->fork);
	return (1);
}

static int	finish_1(t_philo *ph)
{
	pthread_mutex_lock(&ph->t->write);
	ph->t->finished = 1;
	printf("\n\n  { THANKS, BUT WE CANNOT EAT ANYMORE }\n\n");
	return (1);
}

static int	finish_2(t_philo *ph, size_t dead_time, int i)
{
	pthread_mutex_lock(&ph->t->write);
	ph->t->finished = 1;
	printf("[%8zu] PHILO %zu IS DEAD\n", dead_time, ph[i].index);
	return (1);
}

static int	process(t_philo *ph, size_t time, size_t dead_time, int i)
{
	time = current_timestamp(ph->t->beg);
	if (ph->t->nbr_eat_bool)
		if (!ph->t->satiated)
			return (finish_1(ph));
	if (ph->t->nbr_philo == 1)
		return (philo_1(ph));
	if (time >= dead_time)
		return (finish_2(ph, dead_time, i));
	return (0);
}

int	dead(t_philo *ph, int nbr_philo)
{
	size_t	time;
	size_t	dead_time;
	int		i;

	i = 0;
	while (i < nbr_philo)
	{
		if (!ph[i].last_meal)
		{
			time = current_timestamp(ph->t->beg);
			dead_time = time + ph->t->die;
		}
		else
			dead_time = ph[i].last_meal + ph->t->die;
		if (!ph[i].is_eating)
			if (process(ph, time, dead_time, i))
				return (1);
		i++;
	}
	return (0);
}
