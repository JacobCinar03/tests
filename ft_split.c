/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 20:08:59 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/03 20:25:26 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	count_start_find(const char *s, char c, int index_word)
{
	int	i;
	int	word_index;

	i = 0;
	word_index = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && word_index == index_word)
			return (i);
		while (s[i] && s[i] != c)
			i++;
		word_index++;
	}
	return (-1);
}

static int	count_end_find(const char *s, char c, int index_word)
{
	int	i;

	i = count_start_find(s, c, index_word);
	if (i == -1)
		return (-1);
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	*free_split(char **split, int i, int word_count)
{
	while (i < word_count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
	int		start;
	int		end;
	char	**split;

	if (!s)
		return (NULL);
	word_count = count_word(s, c);
	split = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < word_count)
	{
		start = count_start_find(s, c, i);
		end = count_end_find(s, c, i);
		split[i] = ft_substr(s, start, end - start);
		if (!split[i])
			return (free_split(split, i, word_count));
		i++;
	}
	split[i] = NULL;
	return (split);
}
