/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:54 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/08 12:41:14 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_bubble_sort(int *tab, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			++j;
		}
		++i;
	}
}

t_list	*ft_normalize(t_list *lst, int *tab, int size)
{
	t_list	*first;
	int		i;

	ft_bubble_sort(tab, size);
	first = lst;
	while (lst)
	{
		i = 0;
		while (tab[i] != ft_int(lst))
			++i;
		*((int *) lst->content) = i + 1;
		lst = lst->next;
	}
	return (first);
}
