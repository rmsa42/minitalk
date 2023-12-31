/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 15:21:12 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 12:35:20 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include <signal.h>
#include <sys/types.h>

void	send_bit(int server_pid, char c)
{
	int	i;
	int	bit;

	i = 7;
	while (i >= 0)
	{
		bit = (c >> i) & 1;
		if (bit == 0)
			kill(server_pid, SIGUSR1);
		else if (bit == 1)
			kill(server_pid, SIGUSR2);
		pause();
		i--;
	}
}

void	client_signal_handler(int sig, siginfo_t *info, void *ucontext)
{
	info->si_pid = info->si_pid;
	if (sig == SIGUSR1)
		ft_printf("Bit 0 received\n");
	else if (sig == SIGUSR2)
		ft_printf("Bit 1 received \n");
	(void)ucontext;
}

int	main(int argc, char **argv)
{
	int					i;
	int					server_pid;
	struct sigaction	sig;

	if (argc != 3)
	{
		ft_printf("Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	sigemptyset(&(sig.sa_mask));
	sig.sa_flags = SA_SIGINFO;
	sig.sa_sigaction = client_signal_handler;
	if (sigaction(SIGUSR1, &sig, NULL) == -1
		|| sigaction(SIGUSR2, &sig, NULL) == -1)
		exit(EXIT_FAILURE);
	server_pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		send_bit(server_pid, argv[2][i]);
	send_bit(server_pid, '\n');
	return (0);
}
