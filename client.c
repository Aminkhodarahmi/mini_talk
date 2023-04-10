/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:07:43 by akhodara          #+#    #+#             */
/*   Updated: 2023/03/24 16:07:43 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./minitalk.h"

int	main(int argc, char *argv[])
{
	int	server_pid;

	if (argc != 3)
	{
		write(1, "Error, argument must be: <server_pid> <message>\n", 48);
		return (1);
	}
	server_pid = check_valid_pid(argv[1]);
	if (server_pid == 0)
		return (1);
	process_message(argv[2], server_pid);
	return (0);
}
