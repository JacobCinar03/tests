/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/08 19:44:55 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/08 19:48:05 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	power(int base, int exp)
{
	int	result;

	result = 1;
	while (exp > 0)
	{
		result *= base;
		exp--;
	}
	return (result);
}

static char	*result_giver(char *result, int n2, int sign, int index)
{
	int	i;
	int	num;

	i = 0;
	if (sign == 1)
		result[i] = '-';
	num = power(10, index - 1);
	while (i < index)
	{
		result[i + sign] = (n2 / num) % 10 + '0';
		num /= 10;
		i++;
	}
	result[i + sign] = '\0';
	return (result);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		n2;
	int		sign;
	int		index;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n *= -1;
	}
	n2 = n;
	index = 0;
	while (n > 0)
	{
		n = n / 10;
		index++;
	}
	result = (char *)malloc(sizeof(char) * (index + sign + 1));
	if (!result)
		return (NULL);
	return (result_giver(result, n2, sign, index));
}
/*
int main()
{
    printf("%s\n", ft_itoa(421));
    printf("%s\n", ft_itoa(-421));
    printf("%s\n", ft_itoa(0));
    printf("%s\n", ft_itoa(-2147483648));
    printf("%s\n", ft_itoa(2147483647));
}
*/