/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:59:52 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/12 10:43:49 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_list **lst)
{
	t_list	*prev;
	t_list	*item;

	if (!lst || !*lst || !((*lst)->next))
		return ;
	prev = *lst;
	item = prev->next;
	while (item->next)
	{
		prev = item;
		item = item->next;
	}
	prev->next = NULL;
	ft_lstadd_front(lst, item);
}
