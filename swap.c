/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:59:47 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/10 00:10:14 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	t_list	*item;

	if (!lst || !*lst || !((*lst)->next))
		return ;
	item = (*lst)->next;
	(*lst)->next = item->next;
	ft_lstadd_front(lst, item);
}
