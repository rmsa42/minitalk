/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rumachad <rumachad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 13:42:45 by rumachad          #+#    #+#             */
/*   Updated: 2023/09/12 16:22:45 by rumachad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void bits(char c)
{
	int i;
	char a;

	i = 0;
	while (i < 8)
	{
		a = (c >> i) & 1;
		i++;
	}
	printf("%c\n", a);
}

int	main(int argc, char **argv)
{
	int	pid;
	
	if (argc != 3)
		write(1, "\n", 1);
	pid = ft_atoi(argv[1]);
	kill(pid, SIGUSR1);
}
