/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs_for_timings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 10:37:59 by ael-amin          #+#    #+#             */
/*   Updated: 2023/05/13 09:42:05 by ael-amin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long int	in_moment(void)
{
	struct timeval	tp;
	long long int	time;

	gettimeofday(&tp, NULL);
	time = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (time);
}

void	ft_usleep(long long int time)
{
	long long int	curr;

	curr = in_moment();
	time += in_moment();
	while (curr < time)
	{
		usleep(200);
		curr = in_moment();
	}
}

long long int	elapsed_time(t_philosopher *r_philo)
{
	return (in_moment() - r_philo->starting);
}
