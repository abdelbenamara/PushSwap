/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_normalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 12:01:54 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/09 00:33:16 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_shellsort(int *tab, int size)
{
	int	gap;
	int	tmp;
	int	i;
	int	j;

	gap = 1;
	while (gap - 1 < size)
		gap *= 2;
	while (gap - 1 >= 0)
	{
		i = gap;
		while (i < size)
		{
			tmp = tab[i];
			j = i;
			while (j >= gap && tab[j - gap] > tmp)
			{
				tab[j] = tab[j - gap];
				j -= gap;
			}
			tab[j] = tmp;
			++i;
		}
		gap /= 2;
	}
}

t_list	*ft_normalize(t_list *lst, int *tab, int size)
{
	t_list	*first;
	int		i;

	ft_shellsort(tab, size);
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
