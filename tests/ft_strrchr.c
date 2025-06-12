/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:59:28 by ycinarog          #+#    #+#             */
/*   Updated: 2025/05/31 19:02:27 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	ch;
	size_t	len;
	size_t	i;

	len = ft_strlen(s);
	ch = (char)c;
	if (ch == '\0')
		return ((char *)s + len);
	i = 0;
	while (len > i)
	{
		if (s[len - 1 - i] == ch)
			return ((char *)s + (len - 1 - i));
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char bilim[] = "iskender-parasi";
	char beyza[] = "motivasyon-eksikligi";

	printf("%s\n", ft_strrchr(bilim,97));
	printf("%s\n", bilim);
}
*/