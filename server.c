/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:03:39 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/13 16:33:39 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handle(int sig);
void	m(int sig);

int	main()
{
	int	pid;
	

	pid = getpid();
	printf("PID: %d\n\n", pid);
	signal(SIGUSR1, signal_handle);
	signal(SIGUSR2, signal_handle);
	while (1)
		sleep(1);
	return (0);
}

void	signal_handle(int sigk)
{
	if (sigk == SIGUSR1)
		m(0);
	if (sigk == SIGUSR2)
		m(1);
}

void	m(int sig)
{
	static int i;
	static char	c;
	
	i++;
	if (sig == 1)
		c = c | (1 << (8 - i));
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = '\0';
	}
}
