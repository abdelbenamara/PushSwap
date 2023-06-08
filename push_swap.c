/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:14 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/08 12:06:54 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst;
	int		i;
	int		*tab;
	long	*nb;

	if (ac < 2)
		return (0);
	lst = NULL;
	i = 0;
	tab = malloc((ac - 1) * sizeof(int));
	if (!tab)
		return (1);
	while (++i < ac)
	{
		nb = malloc(sizeof(long));
		if (!nb)
			return (ft_lstclear(&lst, &free), free(tab), 1);
		*nb = ft_atol(av[i]);
		if (!ft_check(av[i], *nb, lst) && ft_dprintf(STDERR_FILENO, "Error\n"))
			return (free(nb), ft_lstclear(&lst, &free), free(tab), 1);
		ft_lstadd_back(&lst, ft_lstnew(nb));
		tab[i - 1] = (int) *nb;
	}
	ft_sort(ft_normalize(lst, tab, ac - 1));
	return (ft_lstclear(&lst, &free), free(tab), 0);
}
