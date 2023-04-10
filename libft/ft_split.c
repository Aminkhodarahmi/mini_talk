/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhodara <akhodara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 09:58:50 by akhodara          #+#    #+#             */
/*   Updated: 2022/11/05 14:54:28 by akhodara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_word(char const *s, char c)
{
	char	*dest;
	int		i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	dest = (char *)malloc(sizeof(char) * i + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

static int	count_words(char const *s, char c)
{
	int	words_number;
	int	i;

	i = 0;
	words_number = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || !s[i + 1]))
			words_number++;
		i++;
	}
	return (words_number);
}

char	**ft_split(char const *s, char c)
{
	char	**array_words;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	array_words = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array_words)
		return (NULL);
	while (*s && *s == c)
		s++;
	while (*s)
	{
		array_words[i++] = create_word(s, c);
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
	}
	array_words[i] = 0;
	return (array_words);
}
