/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:03:39 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/14 16:40:24 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	m(int sig, pid_t client_pid)
{
	static int	i;
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
	if (sig == 0)
		kill(client_pid, SIGUSR1);
	else if (sig == 1)
		kill(client_pid, SIGUSR2);
}

void	signal_handle(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR1)
		m(0, info->si_pid);
	else if (sig == SIGUSR2)
		m(1, info->si_pid);
	(void)ucontext;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	pid = getpid();
	ft_printf("PID: %d\n\n", pid);
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handle;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
		pause();
	return (0);
}
