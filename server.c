/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:03:39 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/12 15:57:15 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handle(int sig);

int	main()
{
	int	pid;

	pid = getpid();
	printf("PID: %d\n\n", pid);
	signal(SIGUSR1, signal_handle);
	while (1)
		sleep(1);
	return (0);
}

void	signal_handle(int sigk)
{
	if (sigk == SIGUSR1)
	{
		printf("Signal: %d\n", sigk);
	}
}