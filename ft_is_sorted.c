/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:41:28 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/12 17:50:11 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	ft_is_sorted(t_list *lst, uint8_t asc)
{
	int	prev;

	prev = ft_int(lst);
	lst = lst->next;
	while (lst)
	{
		if ((asc && prev > ft_int(lst)) || (!asc && prev < ft_int(lst)))
			return (0);
		prev = ft_int(lst);
		lst = lst->next;
	}
	return (1);
}
