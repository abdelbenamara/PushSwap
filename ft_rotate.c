/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:59:51 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/12 18:20:47 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list **lst)
{
	t_list	*item;

	if (!lst || !*lst || !((*lst)->next))
		return ;
	item = *lst;
	*lst = item->next;
	item->next = NULL;
	ft_lstadd_back(lst, item);
}
