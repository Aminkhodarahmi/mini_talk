/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:08:04 by akhodara          #+#    #+#             */
/*   Updated: 2023/03/24 16:08:06 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

static char	*ft_cpappend(char *dst, char *src)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	len1 = 0;
	len2 = 0;
	result = NULL;
	if (dst)
		len1 = ft_strlen(dst);
	if (src)
		len2 = ft_strlen(src);
	result = (char *) malloc(len1 + len2 + 1);
	if (!result)
		return (NULL);
	if (dst)
		ft_memcpy(result, dst, len1);
	if (src)
		ft_memcpy(result + len1, src, len2);
	result[len1 + len2] = '\0';
	if (dst)
		free(dst);
	return (result);
}

void	handle_exit(int sig)
{
	if (sig != SIGINT)
		exit(0);
	if (g_message)
		free(g_message);
	g_message = 0;
}

void	process_string(unsigned char c, siginfo_t *sginfo)
{
	static char				buffer[100];
	static int				i;

	buffer[i++] = c;
	if (i >= 99 || !c)
	{
		buffer[i] = 0;
		g_message = ft_cpappend(g_message, buffer);
		if (!g_message)
			exit(1);
		i = 0;
	}
	if (!c)
	{
		write(1, g_message, ft_strlen(g_message));
		free(g_message);
		g_message = 0;
		kill(sginfo->si_pid, SIGUSR2);
	}
}

void	handle_signal(int sig, siginfo_t *sginfo, void *imhere)
{
	static int				bit;
	static unsigned char	c;

	(void)imhere;
	c >>= 1;
	if (sig == SIGUSR2)
		c += 128;
	if (++bit == 8)
	{
		process_string(c, sginfo);
		c = 0;
		bit = 0;
	}
}

void	get_pid(void)
{
	pid_t				pid;
	struct sigaction	sa;
	char				*pid_str;

	sa.sa_sigaction = &handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	signal(SIGINT, &handle_exit);
	pid = getpid();
	pid_str = ft_itoa(pid);
	write(1, "PID: ", 5);
	write(1, pid_str, ft_strlen(pid_str));
	write(1, "\n", 1);
}
