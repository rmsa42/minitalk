/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:21:22 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/18 16:50:18 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

void	bit_arrange(int sig, pid_t client_pid)
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
		bit_arrange(0, info->si_pid);
	else if (sig == SIGUSR2)
		bit_arrange(1, info->si_pid);
	(void)ucontext;
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	sigemptyset(&(sig.sa_mask));
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = signal_handle;
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Waiting for Message...\n\n");
	if (sigaction(SIGUSR1, &sig, NULL) == -1
		|| sigaction(SIGUSR2, &sig, NULL) == -1)
		exit(EXIT_FAILURE);
	while (1)
		pause();
	return (0);
}
