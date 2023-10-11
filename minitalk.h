/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:12:59 by axelchab          #+#    #+#             */
/*   Updated: 2023/07/29 10:56:27 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <execinfo.h>
# include "Libft/libft.h"

char	*ft_strappend(char *str, char c);
void	ft_error(char *str);

#endif
