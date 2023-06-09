/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:38:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/09 19:00:04 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_b(char *op_a, t_list **lst_a, char *op_b, t_list **lst_b)
{
	const int	size = ft_lstsize(*lst_a) + ft_lstsize(*lst_b);
	int			max;

	max = 0;
	while (ft_lstsize(*lst_a) > 3)
	{
		if (ft_lstsize(*lst_b) == max)
			max += size / DIVIDE;
		if (max < 3 || max > size - 3)
			max = size - 3;
		ft_strlcpy(op_a, "", 1);
		ft_strlcpy(op_b, "", 1);
		if (*lst_b && (*lst_b)->next)
			if (ft_int(*lst_b) < ft_int((*lst_b)->next)
				|| ft_int(*lst_b) < ft_int(ft_lstlast(*lst_b)))
				ft_strlcpy(op_b, "rb", 3);
		if (ft_int(*lst_a) <= max)
			ft_strlcpy(op_a, "pb", 3);
		else
			ft_strlcpy(op_a, "ra", 3);
		ft_operate(op_a, lst_a, op_b, lst_b);
	}
}

static void	ft_sort_a(t_list **lst_a, t_list **lst_b)
{
	while (!ft_is_sorted(*lst_a))
	{
		if (ft_int(ft_lstlast(*lst_a)) < ft_int(*lst_a)
			&& ft_int(*lst_a) < ft_int((*lst_a)->next))
			ft_operate("rra", lst_a, "", lst_b);
		else if (ft_int(*lst_a) > ft_int(ft_lstlast(*lst_a))
			&& ft_int(*lst_a) > ft_int((*lst_a)->next))
			ft_operate("ra", lst_a, "", lst_b);
		else if (ft_int(*lst_a) > ft_int((*lst_a)->next)
			|| ft_int((*lst_a)->next) > ft_int(ft_lstlast(*lst_a)))
			ft_operate("sa", lst_a, "", lst_b);
	}
}

static void	ft_sort_b(int min, t_list **lst_a, char *op_b, t_list **lst_b)
{
	const int	size = ft_lstsize(*lst_a) + ft_lstsize(*lst_b);
	int			pos;
	t_list		*tmp;

	ft_strlcpy(op_b, "", 1);
	pos = 0;
	tmp = *lst_b;
	while (tmp && (ft_int(tmp) <= min || (ft_int(tmp) > ft_int(*lst_a)
				&& ft_int(*lst_a) + 1 < ft_int((*lst_a)->next))
			|| (ft_int(ft_lstlast(*lst_a)) != size
				&& ft_int(tmp) < ft_int(ft_lstlast(*lst_a)))) && (++pos))
		tmp = tmp->next;
	if (!tmp)
		pos = 0;
	if (!pos)
		ft_strlcpy(op_b, "pa", 3);
	else if (pos > ft_lstsize(*lst_b) / 2)
		ft_strlcpy(op_b, "rrb", 4);
	else if (pos)
		ft_strlcpy(op_b, "rb", 3);
}

static void	ft_fill_a(char *op_a, t_list **lst_a, char *op_b, t_list **lst_b)
{
	const int	size = ft_lstsize(*lst_a) + ft_lstsize(*lst_b);
	int			min;

	min = ft_lstsize(*lst_b) - size / DIVIDE;
	if (min == ft_lstsize(*lst_b))
		--min;
	if (min < 0)
		min = 0;
	while (ft_lstsize(*lst_b) > min)
	{
		ft_strlcpy(op_a, "", 1);
		ft_sort_b(min, lst_a, op_b, lst_b);
		if (ft_int(*lst_a) + 1 < ft_int((*lst_a)->next)
			|| ft_int(ft_lstlast(*lst_a)) + 1 == ft_int(*lst_a))
		{
			if (!ft_strncmp(op_b, "pa", 3))
				ft_strlcpy(op_b, "", 1);
			if (ft_int(*lst_a) + 1 < ft_int((*lst_a)->next)
				|| ft_int(*lst_a) > ft_int(ft_lstlast(*lst_a)) + 1)
				ft_strlcpy(op_a, "ra", 3);
			else if (ft_int(ft_lstlast(*lst_a)) + 1 == ft_int(*lst_a))
				ft_strlcpy(op_a, "rra", 4);
		}
		ft_operate(op_a, lst_a, op_b, lst_b);
	}
}

void	ft_sort(t_list *lst_a)
{
	t_list	*lst_b;
	char	op_a[4];
	char	op_b[4];

	if (ft_is_sorted(lst_a))
		return ;
	lst_b = NULL;
	ft_fill_b(op_a, &lst_a, op_b, &lst_b);
	ft_sort_a(&lst_a, &lst_b);
	while (lst_b)
		ft_fill_a(op_a, &lst_a, op_b, &lst_b);
	ft_sort_a(&lst_a, &lst_b);
}
