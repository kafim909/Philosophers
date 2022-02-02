/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 11:33:36 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/02 13:24:04 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

size_t	convert(const char *str)
{
	size_t	nbr;
	int		i;

	nbr = 0;
	i = 0;
	while (str[i])
	{
		nbr += str[i] - 48;
		if (str[i + 1])
			nbr *= 10;
		i++;
	}
	return (nbr);
}

size_t	current_timestamp(size_t beg)
{
	struct timeval	tv;
	size_t			time;

	gettimeofday(&tv, NULL);
	time = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	return (time - beg);
}

void	sleep_correction(size_t sleeptime)
{
	size_t	start;

	start = current_timestamp(0);
	while ((current_timestamp(0) - start) < sleeptime / 1000)
		usleep(100);
}
