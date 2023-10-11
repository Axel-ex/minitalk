/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:46:26 by axelchab          #+#    #+#             */
/*   Updated: 2023/07/14 14:44:04 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bin(char c, pid_t server_pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 0x01)
			kill(server_pid, SIGUSR1);
		else
			(kill(server_pid, SIGUSR2));
		usleep(100);
		c >>= 1;
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t	server_pid;
	char	*str;

	if (argc != 3)
		exit (EXIT_FAILURE);
	server_pid = ft_atoi(argv[1]);
	str = argv[2];
	while (*str)
	{
		send_bin(*str, server_pid);
		str++;
	}
	send_bin('\0', server_pid);
	exit(EXIT_SUCCESS);
}
