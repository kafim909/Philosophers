/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:12:30 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/02 15:51:13 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

static void	process(int info, t_philo *ph, t_philo *nxt)
{
	size_t	time;

	time = current_timestamp(ph->t->beg);
	if (info == 1)
		printf("[%8zu] PHILO %zu HAS TAKEN THE FORK N %zu\n",
			time, ph->index, ph->index);
	if (info == 2)
		printf("[%8zu] PHILO %zu HAS TAKEN THE FORK N %zu\n",
			time, ph->index, nxt->index);
	if (info == 3)
		printf("[%8zu] PHILO %zu IS EATING\n", time, ph->index);
	if (info == 5)
		printf("[%8zu] PHILO %zu IS SLEEPING\n", time, ph->index);
	if (info == 6)
		printf("[%8zu] PHILO %zu IS THINKING\n", time, ph->index);
}

int	ft_print(int info, t_philo *ph, t_philo *nxt)
{
	pthread_mutex_lock(&ph->t->write);
	if (ph->t->finished)
	{
		pthread_mutex_unlock(&ph->t->write);
		sleep_correction(10000);
		return (0);
	}
	process(info, ph, nxt);
	pthread_mutex_unlock(&ph->t->write);
	return (1);
}
