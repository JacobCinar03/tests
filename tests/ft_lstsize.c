/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 16:45:31 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/12 18:40:40 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
	int i;

	i = 0;
	while (lst!= NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

/*
int main(void)
{
    t_list *list = NULL;
    t_list *node;

    // 3 tane node oluşturup listeye ekleyelim
    node = ft_lstnew("ilk");
    ft_lstadd_front(&list, node);

    node = ft_lstnew("ikinci");
    ft_lstadd_front(&list, node);

    node = ft_lstnew("üçüncü");
    ft_lstadd_front(&list, node);

    // Listenin eleman sayısını yazdıralım
    printf("Liste eleman sayisi: %d\n", ft_lstsize(list));

    return 0;
}
*/