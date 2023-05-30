/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 22:59:49 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/30 22:08:02 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **lst1, t_list **lst2)
{
	t_list	*item;

	item = *lst2;
	*lst2 = item->next;
	ft_lstadd_front(lst1, item);
}
