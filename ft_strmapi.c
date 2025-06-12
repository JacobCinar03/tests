/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:48:43 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/08 19:48:46 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*result;
	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	result = (char *)malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = f(i, s[i]);
		i++;
	}
	result[i] = '\0';
	return (result);
}
/*
static char function(unsigned int i, char c)
{
    unsigned char result;

    result = (unsigned char)c + i;
    return (char)(result) % 127;
}

int main()
{
    char abi[] = "aaaaa"; 
    printf("%s\n", ft_strmapi(abi, function));

    return 0;
}
*/
//Sorun şu static function strmapinin içinde değil ne yapılmalı onu ayrı tutup main de mi çağırmalı başka bir yol mu bulmalı.