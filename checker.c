/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:21 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/15 01:54:27 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ft_parse_numbers(int ac, char **av, t_list **lst)
{
	int		i;
	long	*nb;

	i = 0;
	while (++i < ac)
	{
		nb = malloc(sizeof(long));
		if (!nb)
			return (ft_lstclear(lst, &free), 0);
		*nb = ft_atol(av[i]);
		if (!ft_check(av[i], *nb, *lst) && ft_dprintf(STDERR_FILENO, "Error\n"))
			return (free(nb), ft_lstclear(lst, &free), 0);
		ft_lstadd_back(lst, ft_lstnew(nb));
	}
	return (1);
}

static uint8_t	ft_process_operation(t_list **lst_a, t_list **lst_b, char *op)
{
	if (!ft_strncmp(op, "rrr\n", 5))
		(ft_reverse_rotate(lst_a), ft_reverse_rotate(lst_b));
	else if (!ft_strncmp(op, "rr\n", 4))
		(ft_rotate(lst_a), ft_rotate(lst_b));
	else if (!ft_strncmp(op, "ss\n", 4))
		(ft_swap(lst_a), ft_swap(lst_b));
	else if (!ft_strncmp(op, "rrb\n", 5))
		(ft_reverse_rotate(lst_b));
	else if (!ft_strncmp(op, "rb\n", 4))
		(ft_rotate(lst_b));
	else if (!ft_strncmp(op, "sb\n", 4))
		(ft_swap(lst_b));
	else if (!ft_strncmp(op, "pa\n", 4))
		(ft_push(lst_a, lst_b));
	else if (!ft_strncmp(op, "rra\n", 5))
		(ft_reverse_rotate(lst_a));
	else if (!ft_strncmp(op, "ra\n", 4))
		(ft_rotate(lst_a));
	else if (!ft_strncmp(op, "sa\n", 4))
		(ft_swap(lst_a));
	else if (!ft_strncmp(op, "pb\n", 4))
		(ft_push(lst_b, lst_a));
	else
		return (free(op), ft_dprintf(STDERR_FILENO, "Error\n"), 0);
	return (free(op), 1);
}

int	main(int ac, char **av)
{
	t_list	*lst_a;
	t_list	*lst_b;
	char	*op;

	if (ac < 2)
		return (0);
	lst_a = NULL;
	if (!ft_parse_numbers(ac, av, &lst_a))
		return (1);
	lst_b = NULL;
	op = get_next_line(STDIN_FILENO);
	while (op)
	{
		if (!ft_process_operation(&lst_a, &lst_b, op))
			return (ft_lstclear(&lst_a, &free), ft_lstclear(&lst_b, &free), 1);
		op = get_next_line(STDIN_FILENO);
	}
	if (ft_is_sorted(lst_a) && ft_lstsize(lst_b) == 0
		&& ft_lstsize(lst_a) == ac - 1)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	return (ft_lstclear(&lst_a, &free), ft_lstclear(&lst_b, &free), 0);
}
