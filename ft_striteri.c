/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:45:30 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/08 19:47:48 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void    ft_striteri(char *s, void (*f)(unsigned int, char*))
{
    size_t i;
    size_t len;

    if (!s || !f)
        return;
    len = ft_strlen(s);
    i = 0;
    while (i < len)
    {
        f(i, &s[i]);
        i++;
    }
}

/*
static void function(unsigned int i, char *c)
{
    unsigned char result;

    result = (unsigned char)(*c) + i;
   *c = (char)(result % 127);
}

int main()
{
    char abi[] = "aaaaa"; 
    ft_striteri(abi, function);
    printf("%s\n", abi);
    return 0;
}

//Sorun şu static function strmapinin içinde değil ne yapılmalı onu ayrı tutup main de mi çağırmalı başka bir yol mu bulmalı.

*/