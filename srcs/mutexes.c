/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutexes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:52:35 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/02 15:24:32 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_mutex(t_philo *ph, int nbr_ph)
{
	int	i;

	i = 0;
	pthread_mutex_init(&ph[i].t->write, NULL);
	pthread_mutex_init(&ph[i].t->sat, NULL);
	while (i < nbr_ph)
	{
		pthread_mutex_init(&ph[i].fork, NULL);
		i++;
	}
	return (1);
}

int	destroy_mutex(t_philo *ph, int nbr_ph)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&ph[i].t->write);
	pthread_mutex_destroy(&ph[i].t->sat);
	while (i < nbr_ph)
	{
		pthread_mutex_destroy(&ph[i].fork);
		i++;
	}
	return (1);
}
