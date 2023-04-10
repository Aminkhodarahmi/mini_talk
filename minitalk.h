/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:07:54 by akhodara          #+#    #+#             */
/*   Updated: 2023/03/24 16:07:56 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <signal.h>
# include "./libft/libft.h"

int		g_send;
char	*g_message;

void		handle_exit(int sig);
void		process_string(unsigned char c, siginfo_t *sginfo);
void		handle_signal(int sig, siginfo_t *sginfo, void *imhere);
void		get_pid(void);
void		handle_sig(int sig);
void		send_char(unsigned char c, int server_pid);
int			check_valid_pid(char *pid_str);
void		process_message(char *message, int server_pid);

#endif
