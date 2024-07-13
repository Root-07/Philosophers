/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:38:41 by ael-amin          #+#    #+#             */
/*   Updated: 2023/05/13 17:55:01 by ael-amin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_param
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_to_eat_opt;
	int				sum_eating;
}	t_param;

typedef struct s_philosopher
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*print;
	int				*can_log;
	int				id;
	long long int	starting;
	long long int	last_meal;
	int				ate;
	t_param			*access;
}	t_philosopher;

typedef struct s_general
{
	pthread_t		*philo;
	pthread_mutex_t	*mutex;
	t_philosopher	*acc_philo;
}	t_general;

int				ft_atoi(char *str);
int				pass_params(int argc, char **argv, t_param *param,
					t_general *addr);
void			assign_params(t_general *var, t_param *param,
					pthread_mutex_t *pr, int *can_log);
int				init_params(t_general *var, t_param *param);
				/*---------------------*/
long long int	in_moment(void);
long long int	elapsed_time(t_philosopher *r_philo);
void			ft_usleep(long long int time);
				/*----------------------*/
int				log_action(t_philosopher *r_philo, char *action);
void			ft_impair(t_philosopher *r_philo);
int				when_eating(t_philosopher *r_philo);
int				one_philo_case(t_philosopher *r_philo);
void			*routine_philo(void *rtn);
void			execution(t_general *var, t_param *param);
int				check_death(t_general *philo, t_param *arg);
				/*-----------------------*/
void			init_mutex(t_general *addr, t_param *param);
int				func_free(t_general *var);
void			join_thread(t_general *addr, t_param *param);
void			destroy_mutex(t_general *addr, t_param *param);
#endif
