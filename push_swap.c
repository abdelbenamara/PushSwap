/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:14 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/18 11:26:04 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_parse_numbers(int ac, char **av, int *tab, t_list **lst)
{
	int		i;
	long	*nb;

	i = 0;
	while (++i < ac)
	{
		nb = malloc(sizeof(long));
		if (!nb)
			return (ft_lstclear(lst, &free), free(tab), 0);
		*nb = ft_atol(av[i]);
		if (!ft_check(av[i], *nb, *lst) && ft_dprintf(STDERR_FILENO, "Error\n"))
			return (free(nb), ft_lstclear(lst, &free), free(tab), 0);
		ft_lstadd_back(lst, ft_lstnew(nb));
		tab[i - 1] = (int) *nb;
	}
	return (1);
}

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

void	ft_normalize(int *tab, t_list **lst)
{
	t_list	*tmp;
	int		i;

	tmp = *lst;
	while (tmp)
	{
		i = 0;
		while (tab[i] != ft_int(tmp))
			++i;
		*((int *) tmp->content) = i + 1;
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	const int	splits = 2 + (ac - 1) / 250;
	int			*tab;
	t_list		*lst;

	if (ac < 2)
		return (0);
	tab = malloc((ac - 1) * sizeof(int));
	if (!tab)
		return (1);
	lst = NULL;
	if (!ft_parse_numbers(ac, av, tab, &lst))
		return (1);
	ft_shellsort(tab, ac - 1);
	ft_normalize(tab, &lst);
	while (!ft_sort(lst, ac - 1, splits))
		;
	return (free(tab), 0);
}
