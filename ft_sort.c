/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:38:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/01 00:25:05 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_list **lst_a)
{
	const int	max = ft_extremum(*lst_a, 1);
	t_list		*lst_b;

	lst_b = NULL;
	while (!ft_is_sorted(*lst_a, 1) || lst_b)
	{
		if (ft_int(*lst_a) > ft_int(ft_lstlast(*lst_a)))
			(ft_rotate(lst_a), ft_printf("ra\n"));
		else if (ft_int((*lst_a)->next) < ft_int(*lst_a)
			|| ft_int((*lst_a)->next) == max)
			(ft_swap(lst_a), ft_printf("sa\n"));
		else if (ft_int((*lst_a)->next) > ft_int(*lst_a)
			&& !ft_is_sorted(*lst_a, 1))
			(ft_push(&lst_b, lst_a), ft_printf("pb\n"));
		else
			(ft_push(lst_a, &lst_b), ft_printf("pa\n"));
		if (lst_b && lst_b->next)
		{
			if (ft_int(lst_b) < ft_int(ft_lstlast(lst_b)))
				(ft_rotate(&lst_b), ft_printf("rb\n"));
			else if (ft_int(lst_b->next) > ft_int(lst_b))
				(ft_swap(&lst_b), ft_printf("sb\n"));
		}
	}
}
