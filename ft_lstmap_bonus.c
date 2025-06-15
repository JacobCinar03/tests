/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycinarog <ycinarog@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 15:52:50 by ycinarog          #+#    #+#             */
/*   Updated: 2025/06/14 20:00:45 by ycinarog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_o;
	t_list	*new_lst;
	void	*n_content;

	if (!lst || !f || !del)
		return (NULL);
	new_lst = NULL;
	while (lst)
	{
		n_content = f(lst->content);
		new_o = ft_lstnew(n_content);
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
*/

t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void*))
{
	t_list	*begin;
	t_list	*work;

	if (lst != NULL && f != NULL)
	{
		begin = ft_lstnew(f(lst->content));
		work = begin;
		while (lst->next)
		{
			lst = lst->next;
			if ((work->next = ft_lstnew(ft_strdup(f(lst->content)))) == NULL)
			{
				ft_lstclear(&begin, del);
				return (NULL);
			}
			work = work->next;
		}
		return (begin);
	}
	return (NULL);
}
