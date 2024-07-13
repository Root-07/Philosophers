/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_of_philosophers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:34:56 by ael-amin          #+#    #+#             */
/*   Updated: 2023/05/13 17:54:30 by ael-amin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	total_eat(t_philosopher *philo)
{
	philo->ate++;
	if (philo->ate == philo->access->num_to_eat_opt)
		philo->access->sum_eating++;
}

void	*routine_philo(void *rtn)
{
	t_philosopher	*r_philo;

	r_philo = (t_philosopher *) rtn;
	r_philo->last_meal = elapsed_time(r_philo);
	ft_impair(r_philo);
	while (1)
	{
		pthread_mutex_lock(r_philo->left_fork);
		log_action(r_philo, "has taken a fork");
		if (one_philo_case(r_philo))
			return (pthread_mutex_unlock(r_philo->left_fork), NULL);
		pthread_mutex_lock(r_philo->right_fork);
		log_action(r_philo, "has taken a fork");
		if (when_eating(r_philo))
			return (NULL);
		ft_usleep(r_philo->access->time_to_eat);
		r_philo->last_meal = elapsed_time(r_philo);
		pthread_mutex_unlock(r_philo->left_fork);
		pthread_mutex_unlock(r_philo->right_fork);
		log_action(r_philo, "is sleeping");
		total_eat(r_philo);
		ft_usleep(r_philo->access->time_to_sleep);
		log_action(r_philo, "is thinking");
	}
	return (NULL);
}

void	execution(t_general *var, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->number_of_philosophers)
	{
		pthread_create(&var->philo[i], NULL, routine_philo, &var->acc_philo[i]);
		i++;
	}
}

int	verify_sum_eating(t_general *philo, t_param *arg)
{
	if (arg->sum_eating == arg->number_of_philosophers)
	{
		destroy_mutex(philo, arg);
		return (1);
	}
	return (0);
}

int	check_death(t_general *philo, t_param *arg)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < arg->number_of_philosophers)
		{
			if (verify_sum_eating(philo, arg))
				return (1);
			if (elapsed_time(&philo->acc_philo[i])
				- philo->acc_philo[i].last_meal > arg->time_to_die)
			{
				pthread_mutex_lock(philo->acc_philo->print);
				*philo->acc_philo->can_log = 0;
				printf("%lld %d died\n",
					elapsed_time(&philo->acc_philo[i]), philo->acc_philo[i].id);
				pthread_mutex_unlock(philo->acc_philo->print);
				return (1);
			}
			i++;
		}
		usleep(100);
	}
}
