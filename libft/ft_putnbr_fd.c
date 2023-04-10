/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:55:59 by akhodara          #+#    #+#             */
/*   Updated: 2022/10/27 09:57:43 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(long n)
{
	unsigned int	count;

	count = 0;
	if (n == 0)
		return (++count);
	while (n)
	{
		count++;
		n /= 10;
	}
	return (count);
}

static void	clear_buf(char *s, int size)
{
	int		index;

	index = 0;
	while (index < size)
		s[index++] = 0;
}

void	ft_putnbr_fd(int n, int fd)
{
	long			new_n;
	char			buf[0x1F];
	unsigned int	index;

	new_n = (long)n;
	index = int_len(new_n) - 1;
	clear_buf(buf, 31);
	if (new_n == 0)
		ft_putchar_fd('0', fd);
	if (new_n < 0)
	{
		ft_putchar_fd('-', fd);
		new_n *= -1;
	}
	while (new_n)
	{
		buf[index] = (char)((new_n % 10) + '0');
		new_n /= 10;
		index--;
	}
	ft_putstr_fd(buf, fd);
}
