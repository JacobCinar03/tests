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

	i = count_start_find(s, c, index_word); // kelimenin başlangıç index'i

	if (i == -1)
		return -1; // kelime yoksa -1 döndür
	while (s[i] && s[i] != c)
		i++; // kelimenin sonuna kadar git
	return (i); // kelimenin bittiği index (ayraç ya da \0)
}

static void	free_split(char **split, int i)
{
	while (i >= 0)
	{
		free(split[i]);
		i--;
	}
	free(split);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_count;
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
		int start = count_start_find(s, c, i);
		int end = count_end_find(s, c, i);
		split[i] = ft_substr(s, start, end - start);
		if (!split[i])
		{
			free_split(split, i - 1);
			return (NULL); // memory allocation error
		}
		i++;
	}
	split[i] = NULL;
	return (split);
}


/*char	**ft_split(char const *s, char c)
{
	int	i;
	int word_index;
	char *str[ft_strlen(s)];

	word_index = 0;
	i = 0;
	while(count_word(s, c) > i)
	{
		*str[i] = ft_substr(s, count_start_find(s, c, i), count_end_find(s, c, i) - count_start_find(s, c, i));
		i++;
	}
	return(str);
}*/

/*
int main(void)
{
	char **abisi;
	char str[] = "--merhaba--dunya---bu-bir-test";
	char delim = '-';

	abisi = ft_split(str, delim);
	free(abisi[0]);
	abisi[0] = malloc(3);
	abisi[0][0] = 's';
	abisi[0][1] = 'a';
	abisi[0][2] = '\0';

		printf("%d. kelime: %s\n", 0, abisi[0]);
		printf("%d. kelime: %s\n", 1, abisi[1]);
		printf("%d. kelime: %s\n", 2, abisi[2]);
		printf("%d. kelime: %s\n", 3, abisi[3]);
		printf("%d. kelime: %s\n", 4, abisi[4]);
	// Belleği temizlemeyi unutma
	for (int i = 0; abisi[i]; i++)
		free(abisi[i]);
	free(abisi);


	return 0;
}
*/