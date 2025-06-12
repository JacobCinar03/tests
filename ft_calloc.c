/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 13:58:11 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/01 14:52:25 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
int main(int argc, char const *argv[])
{
	int* p2 = ft_calloc(1, sizeof(p2[4]));
	
    if (p2)
    {
        for (int n = 0; n < 4; ++n) // print the array
            printf("p2[%d] == %d\n", n, p2[n]);
    }
	free(p2);
	return 0;
}
*/