/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:14 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/10 02:45:08 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static uint8_t	ft_check(const char *str, long nb, t_list *lst)
{
	int		i;

	i = 0;
	if (str[0] == '-')
		i = 1;
	while (ft_isdigit(str[i]))
		++i;
	if (!str[0] || i > 10 + (str[0] == '-') || str[i])
		return (0);
	if (nb < -2147483648 || nb > 2147483647)
		return (0);
	while (lst)
	{
		if (nb == *((long *) lst->content))
			return (0);
		lst = lst->next;
	}
	return (1);
}

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
	return (ft_lstclear(&lst, &free), 0);
}
