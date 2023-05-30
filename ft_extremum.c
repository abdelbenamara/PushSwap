/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extremum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:03:50 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/12 15:41:55 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_extremum(t_list *lst, uint8_t max)
{
	int	extremum;

	extremum = ft_int(lst);
	lst = lst->next;
	while (lst)
	{
		if ((max && extremum < ft_int(lst)) || (!max && extremum > ft_int(lst)))
			extremum = ft_int(lst);
		lst = lst->next;
	}
	return (extremum);
}
