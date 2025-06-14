






t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
t_list *new_lst;

new_lst = NULL;
while(lst != NULL)
{
   n_content = f(lst->content);
   ft_lstnew(n_content)
}
}
