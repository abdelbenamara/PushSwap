/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:14 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/14 12:53:57 by abenamar         ###   ########.fr       */
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

t_list	*ft_normalize(t_list *lst, int *tab)
{
	t_list	*new;
	int		i;
	int		*nb;

	new = NULL;
	while (lst)
	{
		i = 0;
		while (tab[i] != ft_int(lst))
			++i;
		nb = malloc(sizeof(int));
		if (!nb)
			return (ft_lstclear(&new, &free), NULL);
		*nb = i + 1;
		ft_lstadd_back(&new, ft_lstnew(nb));
		lst = lst->next;
	}
	return (new);
}

static int	ft_find_best_parts(t_list *lst, int *tab, int size)
{
	t_list	*tmp;
	int		parts;
	int		best;
	int		score;
	int		test;

	parts = 2;
	tmp = ft_normalize(lst, tab);
	if (!tmp)
		return (-1);
	best = ft_sort(tmp, size, parts, 0);
	test = parts;
	while (++test, test < size / 100 + 3)
	{
		tmp = ft_normalize(lst, tab);
		if (!tmp)
			return (-1);
		score = ft_sort(tmp, size, test, 0);
		if (score < best)
		{
			best = score;
			parts = test;
		}
	}
	return (parts);
}

int	main(int ac, char **av)
{
	int		*tab;
	t_list	*lst;
	int		parts;
	t_list	*norm;

	if (ac < 2)
		return (0);
	tab = malloc((ac - 1) * sizeof(int));
	if (!tab)
		return (1);
	lst = NULL;
	if (!ft_parse_numbers(ac, av, tab, &lst))
		return (1);
	ft_shellsort(tab, ac - 1);
	parts = -1;
	while (parts == -1)
		parts = ft_find_best_parts(lst, tab, ac - 1);
	norm = ft_normalize(lst, tab);
	if (!norm)
		return (ft_lstclear(&lst, &free), free(tab), 1);
	ft_sort(norm, ac - 1, parts, 1);
	return (ft_lstclear(&lst, &free), free(tab), 0);
}
