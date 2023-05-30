/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:35:10 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/12 17:46:40 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

uint8_t	ft_check(const char *str, long nb, t_list *lst)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i = 1;
	while (ft_isdigit(str[i]))
		++i;
	if (!str[0] || (!i || i > 10) + (str[0] == '-') || str[i])
		return (0);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	while (lst)
	{
		if (nb == ft_int(lst))
			return (0);
		lst = lst->next;
	}
	return (1);
}
