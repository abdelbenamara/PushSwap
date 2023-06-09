/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:41:32 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/09 18:42:08 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	ft_is_sorted(t_list *lst)
{
	int	prev;

	prev = ft_int(lst);
	lst = lst->next;
	while (lst)
	{
		if (prev > ft_int(lst))
			return (0);
		prev = ft_int(lst);
		lst = lst->next;
	}
	return (1);
}
