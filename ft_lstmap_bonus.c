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
/*
#include "libft.h"

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

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
    t_list *new_list;
    t_list *new_obj;
    
    if (!lst || !f || !del)
        return (NULL);
    new_list = NULL;
    /* loop over the existing list */
    while (lst)
    {
        /* create a new object with the content being the result
         * of the application of the function f on the current element's
         * content
         */
        new_obj = ft_lstnew(f(lst->content));
        if (!new_obj)
        {
            /* if the new object is null, clear the new list */
            ft_lstclear(&new_list, del);
            return (NULL);
        }
        /* if there is a new object, add it to the back of the new list */
        ft_lstadd_back(&new_list, new_obj);
        lst = lst->next;
    }
    /* finally, we return the new list */
    return (new_list);
}
