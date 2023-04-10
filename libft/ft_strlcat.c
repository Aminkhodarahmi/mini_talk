/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 09:57:40 by akhodara          #+#    #+#             */
/*   Updated: 2023/03/24 12:06:55 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t len)
{
	size_t	j;
	size_t	k;

	j = 0;
	k = 0;
	if (!dest && len == 0)
		return (0);
	while (dest[j] && j < len)
		j++;
	while ((src[k]) && ((j + k + 1) < len))
	{
		dest[j + k] = src[k];
		k++;
	}
	if (j != len)
		dest[j + k] = '\0';
	return (j + ft_strlen(src));
}
