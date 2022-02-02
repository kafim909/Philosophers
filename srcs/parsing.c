/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtournay <mtournay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:50:42 by mtournay          #+#    #+#             */
/*   Updated: 2022/02/02 14:59:20 by mtournay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	error_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc < 5 || argc > 6)
	{
		write(2, "BAD INPUT\n", 10);
		return (0);
	}	
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]))
			{
				write(2, "BAD INPUT\n", 10);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_int_max(t_shared t)
{
	if (t.nbr_philo > 200 || t.die > INT_MAX || t.eat > INT_MAX
		|| t.sleep > INT_MAX)
		return (0);
	if (t.nbr_eat_bool)
		if (t.satiated > INT_MAX)
			return (0);
	return (1);
}

static t_shared	get_arg(char **argv, int argc)
{
	t_shared	t;

	t.nbr_philo = convert(argv[1]);
	t.die = convert(argv[2]);
	t.eat = convert(argv[3]);
	t.sleep = convert(argv[4]);
	t.beg = 0;
	t.beg = current_timestamp(0);
	t.nbr_eat_bool = 0;
	t.finished = 0;
	if (argc == 6)
	{
		t.nbr_eat_bool = 1;
		t.satiated = convert(argv[5]);
		t.satiated *= t.nbr_philo;
	}
	return (t);
}

int	init_struct(t_philo *ph, int nbr_ph, char **argv, int argc)
{
	int			i;
	t_shared	*t;

	t = malloc(sizeof(t_shared));
	if (!t)
		return (0);
	*t = get_arg(argv, argc);
	if (!check_int_max(*t))
	{	
		free(t);
		write(2, "BAD INPUT\n", 10);
		return (0);
	}
	i = 0;
	while (i < nbr_ph)
	{
		ph[i].t = t;
		ph[i].last_meal = 0;
		ph[i].is_eating = 0;
		ph[i].first = ph;
		ph[i].index = i;
		i++;
	}
	return (1);
}
