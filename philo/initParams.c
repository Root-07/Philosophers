/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initParams.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 18:06:04 by ael-amin          #+#    #+#             */
/*   Updated: 2023/05/13 13:16:44 by ael-amin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		res = res * 10 + (str[i++] - '0');
	return (res * sign);
}

void	func_alloc(t_general *arr, t_param *param)
{
	arr->philo = malloc(sizeof(pthread_t) * param->number_of_philosophers);
	arr->mutex
		= malloc(sizeof(pthread_mutex_t) * param->number_of_philosophers);
	arr->acc_philo
		= malloc(sizeof(t_philosopher) * param->number_of_philosophers);
}

int	pass_params(int argc, char **argv, t_param *param, t_general *addr)
{
	if (argc > 4)
	{
		param->sum_eating = 0;
		param->number_of_philosophers = ft_atoi(argv[1]);
		param->time_to_die = ft_atoi(argv[2]);
		param->time_to_eat = ft_atoi(argv[3]);
		param->time_to_sleep = ft_atoi(argv[4]);
		if (param->number_of_philosophers <= 0 || param->time_to_die <= 0
			|| param->time_to_eat <= 0 || param->time_to_sleep <= 0)
			return (1);
		if (argc >= 6)
		{
			param->num_to_eat_opt = ft_atoi(argv[5]);
			if (param->num_to_eat_opt <= 0)
				return (1);
		}
		else
			param->num_to_eat_opt = -1;
		func_alloc(addr, param);
		return (0);
	}
	return (1);
}

void	assign_params(t_general *var, t_param *param,
		pthread_mutex_t *pr, int *can_log)
{
	int				i;
	long long int	start;

	start = in_moment();
	while (i < param->number_of_philosophers)
	{
		var->acc_philo[i].id = i + 1;
		var->acc_philo[i].starting = start;
		var->acc_philo[i].access = param;
		var->acc_philo[i].left_fork = &var->mutex[i];
		var->acc_philo[i].right_fork
			= &var->mutex[(i + 1) % param->number_of_philosophers];
		var->acc_philo[i].print = pr;
		var->acc_philo[i].can_log = can_log;
		var->acc_philo[i].ate = 0;
		i++;
	}
	execution(var, param);
}

int	init_params(t_general *var, t_param *param)
{
	int				*can_log;
	pthread_mutex_t	*pr;

	pr = malloc(sizeof(pthread_mutex_t));
	if (pr == NULL)
		return (0);
	if (pthread_mutex_init(pr, NULL))
	{
		free(pr);
		return (1);
	}
	can_log = malloc(sizeof(int));
	*can_log = 1;
	assign_params(var, param, pr, can_log);
	free(can_log);
	return (0);
}
