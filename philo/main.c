/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-amin <ael-amin@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 18:14:29 by ael-amin          #+#    #+#             */
/*   Updated: 2023/05/13 13:14:46 by ael-amin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_param		argument;
	t_general	addr;

	if (pass_params(argc, argv, &argument, &addr))
		return (1);
	init_mutex(&addr, &argument);
	init_params(&addr, &argument);
	if (check_death(&addr, &argument))
		usleep(500);
	join_thread(&addr, &argument);
	destroy_mutex(&addr, &argument);
	func_free(&addr);
	return (0);
}
