/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:54:13 by akhodara          #+#    #+#             */
/*   Updated: 2022/10/30 15:24:57 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char const *s, int fd)
{
	unsigned int	i;
	char			c;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		c = s[i];
		write(fd, &c, 1);
		i++;
	}
	c = '\n';
	write(fd, &c, 1);
}
