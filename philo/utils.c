/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 20:08:58 by ael-amin          #+#    #+#             */
/*   Updated: 2023/05/13 13:12:01 by ael-amin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_mutex(t_general *addr, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->number_of_philosophers)
	{
		pthread_mutex_init(&addr->mutex[i], NULL);
		i++;
	}
}

void	join_thread(t_general *addr, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->number_of_philosophers)
	{
		pthread_join(addr->philo[i], NULL);
		i++;
	}
}

void	destroy_mutex(t_general *addr, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->number_of_philosophers)
	{
		pthread_mutex_destroy(&addr->mutex[i]);
		pthread_detach(addr->philo[i]);
		i++;
	}
	pthread_mutex_destroy(addr->acc_philo->print);
}

int	func_free(t_general *var)
{
	free(var->mutex);
	free(var->acc_philo);
	free(var->philo);
	free(var->acc_philo->print);
	return (1);
}
