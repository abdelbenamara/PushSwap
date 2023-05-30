/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:14 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/12 17:44:26 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*lst;
	int		i;
	long	*nb;

	if (ac < 2)
		return (0);
	lst = NULL;
	i = 0;
	while (++i < ac)
	{
		nb = malloc(sizeof(long));
		if (!nb)
			return (ft_lstclear(&lst, &free), 1);
		*nb = ft_atol(av[i]);
		if (!ft_check(av[i], *nb, lst) && ft_dprintf(STDERR_FILENO, "Error\n"))
			return (free(nb), ft_lstclear(&lst, &free), 1);
		ft_lstadd_back(&lst, ft_lstnew(nb));
	}
	ft_sort(&lst);
	return (ft_lstclear(&lst, &free), 0);
}
