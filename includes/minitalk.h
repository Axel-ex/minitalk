/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achabrer <achabrer@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 17:12:59 by axelchab          #+#    #+#             */
/*   Updated: 2023/10/11 16:43:45 by achabrer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <execinfo.h>
# include "../Libft/libft.h"

// =============================================================================
// CLIENT.C
// =============================================================================
/**
 * @brief The least significant bit is compared using & bitwise
 * operation with 0x01, returning 1 if te compared bit is 1.
 * The appropriated signal is sent to the process corresponding
 * to server_pid. c is then right shifted until the most
 * significant bit is reached.
 * 
 * @param c char to send.
 * @param server_pid process ID of ./server
 */
void	send_bin(char c, pid_t server_pid);

// =============================================================================
// SERVER.C
// =============================================================================
/**
 * @brief the variable bit takes the value 0 or 1 depending on
 * the signal it receives. it is append to the static char c using
 * the or bitwise operation. When the MSB is reached, the char
 * is append to the str. if c is a null byte, we reached the end 
 * of the str so we print it.
 * 
 * @param signum signal ID
 */
void	read_bites(int signum);
/**
 * @brief set sigaction structures handlers and sa_mask.
 * sa_mask is set on SIGUSR1 and SIGUSR2 respectivaly, impeding
 * one from interrupting the other when beeing executed.
 */
void	ft_install_handler(void);

// =============================================================================
// UTIL.C
// =============================================================================
/**
 * @brief append a character to the end of the string. Allocate
 * the string if it doesn't exist yet.
 * 
 * @param str string to append to
 * @param c char to append
 * @return char* string  
 */
char	*ft_strappend(char *str, char c);
/**
 * @brief print error message and exit the program.
 * 
 * @param erorr_msg message to print
 */
void	ft_error(char *error_msg);

#endif
