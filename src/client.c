/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:42:45 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/19 12:34:56 by rumachad         ###   ########.fr       */
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
		usleep(100);
		i--;
	}
}

int	main(int argc, char **argv)
{
	int					i;
	int					server_pid;

	if (argc != 3)
	{
		ft_printf("Invalid arguments\n");
		exit(EXIT_FAILURE);
	}
	server_pid = ft_atoi(argv[1]);
	i = -1;
	while (argv[2][++i])
		send_bit(server_pid, argv[2][i]);
	send_bit(server_pid, '\n');
	return (0);
}
