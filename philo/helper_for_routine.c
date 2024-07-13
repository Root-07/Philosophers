/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_for_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 19:00:07 by ael-amin          #+#    #+#             */
/*   Updated: 2023/05/13 17:53:05 by ael-amin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	log_action(t_philosopher *r_philo, char *action)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(r_philo->print);
	if (*r_philo->can_log)
		printf("%lld %d %s\n", elapsed_time(r_philo), r_philo->id, action);
	else
		ret = 1;
	pthread_mutex_unlock(r_philo->print);
	return (ret);
}

void	ft_impair(t_philosopher *r_philo)
{
	if (r_philo->id % 2)
	{
		log_action(r_philo, "is thinking");
		ft_usleep(r_philo->access->time_to_eat);
	}
}

int	when_eating(t_philosopher *r_philo)
{
	if (log_action(r_philo, "is eating") == 1)
	{
		pthread_mutex_unlock(r_philo->left_fork);
		pthread_mutex_unlock(r_philo->right_fork);
		return (1);
	}
	return (0);
}

int	one_philo_case(t_philosopher *r_philo)
{
	int	stop;

	if (r_philo->access->number_of_philosophers == 1)
	{
		stop = 0;
		while (stop == 0)
		{
			pthread_mutex_lock(r_philo->print);
			if (*r_philo->can_log == 0)
				stop = 1;
			pthread_mutex_unlock(r_philo->print);
		}
		return (1);
	}
	return (0);
}
