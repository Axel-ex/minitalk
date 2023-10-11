/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:20:49 by achabrer          #+#    #+#             */
/*   Updated: 2023/07/29 14:19:37 by achabrer         ###   ########.fr       */
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

void	ft_install_handler(void)
{
	struct sigaction	hand1;
	struct sigaction	hand2;

	hand1.sa_handler = &read_bites;
	hand2.sa_handler = &read_bites;
	sigemptyset(&hand1.sa_mask);
	sigemptyset(&hand2.sa_mask);
	sigaddset(&hand1.sa_mask, SIGUSR2);
	sigaddset(&hand2.sa_mask, SIGUSR1);
	if (sigaction(SIGUSR1, &hand1, NULL) == -1)
		ft_error("Error while setting handler 1");
	if (sigaction(SIGUSR2, &hand2, NULL) == -1)
		ft_error("Error while setting handler 2");
}

int	main(void)
{
	ft_printf("Pid: %d\n", getpid());
	ft_install_handler();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
