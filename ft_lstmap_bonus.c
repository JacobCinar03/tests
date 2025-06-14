/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:52:50 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/14 19:17:22 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	if (!lst && !f && !del)
		return (NULL);
	t_list	*new_o;
	t_list	*new_lst;
	void	*n_content;

	new_lst = NULL;
	while (lst)
	{
		n_content = f(lst->content); // lst content f den n'ye aktarılır.
		new_o = ft_lstnew(n_content); // yeni liste başlatılır ilk elde edilen değerle
		if (!new_o)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, new_o);
		lst = lst->next;
	}
	return (new_lst);
}
