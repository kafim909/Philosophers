/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:53:31 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/02 15:24:49 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static int	take_forks(t_philo *ph, t_philo *nxt)
{
	pthread_mutex_lock(&ph->fork);
	ft_print(1, ph, ph);
	pthread_mutex_lock(&nxt->fork);
	ft_print(2, ph, nxt);
	ft_print(3, ph, nxt);
	ph->is_eating = 1;
	return (1);
}

int	eat_process(t_philo *ph, t_philo *nxt)
{
	take_forks(ph, nxt);
	ph->last_meal = current_timestamp(ph->t->beg);
	sleep_correction(ph->t->eat * 1000);
	ph->is_eating = 0;
	if (ph->t->nbr_eat_bool)
	{
		pthread_mutex_lock(&ph->t->sat);
		ph->t->satiated--;
		pthread_mutex_unlock(&ph->t->sat);
	}
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(&nxt->fork);
	return (1);
}

int	thread_process(t_philo *ph, t_philo *nxt)
{
	ph->is_eating = 0;
	eat_process(ph, nxt);
	ft_print(5, ph, ph);
	sleep_correction(ph->t->sleep * 1000);
	ft_print(6, ph, ph);
	return (0);
}

void	*thread(void *arg)
{
	t_philo	*ph;
	t_philo	*nxt;

	ph = (t_philo *)arg;
	nxt = (t_philo *)arg;
	if (ph->index < ph->t->nbr_philo -1)
		nxt++;
	else
		nxt = ph->first;
	if (ph->index % 2)
		sleep_correction(1500);
	while (1)
		if (thread_process(ph, nxt))
			return (NULL);
	return (NULL);
}
