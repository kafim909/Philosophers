/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:51:05 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/02 15:51:37 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_exit(t_philo *ph, int nbr_ph, int bool)
{
	sleep_correction(1000);
	if (bool)
	{
		free(ph->t);
		destroy_mutex(ph, nbr_ph);
	}
	free(ph);
	return (0);
}

int	launch(t_philo *ph, int nbr_ph)
{
	int	i;

	i = 0;
	while (i < nbr_ph)
	{
		if (pthread_create(&ph[i].id, NULL, &thread, (&ph[i])))
			return (0);
		pthread_detach(ph[i].id);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int		nbr_ph;
	int		i;
	t_philo	*ph;

	i = 0;
	if (!error_check(argc, argv))
		return (0);
	nbr_ph = convert(argv[1]);
	ph = malloc(sizeof(t_philo) * nbr_ph);
	if (!ph)
		return (0);
	if (!init_struct(ph, nbr_ph, argv, argc))
		return (ft_exit(ph, nbr_ph, 0));
	init_mutex(ph, nbr_ph);
	if (!launch(ph, nbr_ph))
		return (ft_exit(ph, nbr_ph, 1));
	while (1)
	{
		if (dead(ph, nbr_ph))
			break ;
	}
	return (ft_exit(ph, nbr_ph, 1));
}
