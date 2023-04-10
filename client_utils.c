/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:07:31 by akhodara          #+#    #+#             */
/*   Updated: 2023/03/24 16:07:36 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

void	handle_sig(int sig)
{
	if (sig == SIGINT)
		g_send = 0;
	else if (sig == SIGUSR2 && g_send)
	{
		write(1, "Received!\n", 10);
		exit(0);
	}
}

void	send_char(unsigned char c, int server_pid)
{
	int	bit;
	int	i;

	i = 0;
	while (i < 8)
	{
		bit = c & (1 << i);
		if (bit)
			kill(server_pid, SIGUSR2);
		else
			kill(server_pid, SIGUSR1);
		usleep(100);
		i++;
	}
}

int	check_valid_pid(char *pid_str)
{
	int	pid;

	pid = ft_atoi(pid_str);
	if (pid == 0 || kill(pid, 0) == -1)
	{
		write(1, "is not a valid pid\n", 19);
		ft_putstr_fd(pid_str, 1);
		return (0);
	}
	return (pid);
}

void	process_message(char *message, int server_pid)
{
	int	i;

	g_send = 1;
	i = 0;
	signal(SIGUSR2, handle_sig);
	signal(SIGINT, handle_sig);
	while (g_send && message[i] && kill(server_pid, 0) != -1)
	{
		send_char((unsigned char) message[i], server_pid);
		i++;
	}
	if (kill(server_pid, 0) != -1)
	{
		send_char(0, server_pid);
		pause();
	}
	else
		write(1, "ERROR: Connection lost\n", 23);
}
