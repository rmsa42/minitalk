/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 12:03:39 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 11:35:53 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include <signal.h>
# include <sys/types.h>

void	bit_arrange(int sig)
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
}

void	signal_handler(int sig)
{
	if (sig == SIGUSR1)
		bit_arrange(0);
	else if (sig == SIGUSR2)
		bit_arrange(1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sig;

	sig.sa_flags = 0;
	sigemptyset(&(sig.sa_mask));
	sig.sa_handler = signal_handler;
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
