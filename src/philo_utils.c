/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttomori <ttomori@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 21:47:25 by ttomori           #+#    #+#             */
/*   Updated: 2022/06/29 18:38:01 by ttomori          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	free_philo(t_philo *philo);

void	*main_loop(void *content)
{
	return (NULL);
}

void	free_philos_circular(t_philo *head)
{
	t_philo	*philo;
	t_philo	*tmp;

	philo = head;
	while (philo->index != NIL)
	{
		tmp = philo->next;
		free_philo(philo);
		philo = tmp;
	}
}

static void	free_philo(t_philo *philo)
{
	free(philo->fork_mutex);
	pthread_mutex_destroy(philo->fork_mutex);
	free(philo->fork_mutex);
}
