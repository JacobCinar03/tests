/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 20:20:44 by ycinarog          #+#    #+#             */
/*   Updated: 2025/05/31 21:07:09 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*x1;
	unsigned char	*x2;
	size_t			i;

	x1 = (unsigned char *)s1;
	x2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (x1[i] != x2[i])
			return (x1[i] - x2[i]);
		i++;
	}
	return (0);
}

/*
int main(void)
{
	char q1[] = "asdfghjewrwerke";
	char q2[] = "asdfghjewwwekq";

	printf("%d\n", ft_strncmp(q1, q2, 20));


	printf("\n adres \n");
	printf("%d\n",ft_memcmp(q1, q2, 20));
	printf("...%p... -- q1 \n", q1);
	printf("...%p... -- q2 \n", q2);
}
*/