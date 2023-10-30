/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:20:49 by achabrer          #+#    #+#             */
/*   Updated: 2023/10/30 12:38:58 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*g_str = NULL;

void	read_bites(int signum)
{
	static int				byte_index = 0;
	static char				c = 0;
	unsigned char			bit;

	bit = (signum == SIGUSR1);
	c |= (bit << byte_index++);
	if (byte_index == 8)
	{
		g_str = ft_strappend(g_str, c);
		if (!g_str)
			exit(EXIT_FAILURE);
		if (c == 0)
		{
			ft_printf("%s\n", g_str);
			free(g_str);
			g_str = NULL;
		}
		c = 0;
		byte_index = 0;
	}
}

int	main(void)
{
	ft_printf("Pid: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, read_bites);
		signal(SIGUSR2, read_bites);
	}
	return (EXIT_SUCCESS);
}
