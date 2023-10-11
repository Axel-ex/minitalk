/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 13:58:01 by achabrer          #+#    #+#             */
/*   Updated: 2023/07/29 10:56:33 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strappend(char *str, char c)
{
	char	*new;
	int		i;

	i = 0;
	if (!str)
	{
		new = malloc(2);
		new[0] = c;
		new[1] = '\0';
		return (new);
	}
	new = malloc(ft_strlen(str) + 2);
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	free(str);
	return (new);
}

void	ft_error(char *str)
{
	ft_printf("%s", str);
	exit(EXIT_FAILURE);
}
