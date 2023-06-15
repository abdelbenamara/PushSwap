/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:59:49 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/15 00:53:23 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **lst_dst, t_list **lst_src)
{
	t_list	*item;

	if (!lst_src || !*lst_src)
		return ;
	item = *lst_src;
	*lst_src = item->next;
	ft_lstadd_front(lst_dst, item);
}
