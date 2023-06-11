/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:38:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/11 22:50:32 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_b(char *op_a, t_list **lst_a, char *op_b, t_list **lst_b)
{
	const int	size = ft_lstsize(*lst_a) + ft_lstsize(*lst_b);
	int			lst_a_size;
	int			lst_b_size;
	int			max;

	lst_a_size = ft_lstsize(*lst_a);
	lst_b_size = ft_lstsize(*lst_b);
	max = 0;
	while (lst_a_size > 3)
	{
		if (lst_b_size == max)
			max += lst_a_size / BRACKETS;
		if (lst_b_size == max || max < 3 || max > size - 3)
			max = size - 3;
		ft_strlcpy(op_b, "", 1);
		if (*lst_b && (*lst_b)->next && (ft_int(*lst_b) < max / 2
				|| ft_int(*lst_b) < ft_int(ft_lstlast(*lst_b))))
			ft_strlcpy(op_b, "rb", 3);
		if (ft_int(*lst_a) <= max && (++lst_b_size))
			(ft_strlcpy(op_a, "pb", 3), --lst_a_size);
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

static int	ft_sort_b(int min, t_list **lst_a, char *op_b, t_list **lst_b)
{
	const int	size = ft_lstsize(*lst_a) + ft_lstsize(*lst_b);
	int			lst_b_size;
	int			pos;
	t_list		*tmp;

	(ft_strlcpy(op_b, "", 1), lst_b_size = ft_lstsize(*lst_b));
	pos = 0;
	tmp = *lst_b;
	while (tmp && (ft_int(tmp) <= min || (ft_int(tmp) > ft_int(*lst_a)
				&& (ft_int(tmp) > ft_int((*lst_a)->next)
					|| ft_int(tmp) < ft_int(*lst_a)))
			|| (ft_int(ft_lstlast(*lst_a)) != size
				&& ft_int(tmp) < ft_int(ft_lstlast(*lst_a)))) && (++pos))
		tmp = tmp->next;
	if (!tmp || ft_int(*lst_b) - 1 == ft_int(*lst_a))
		return (lst_b_size);
	else if (pos > lst_b_size / 2 || ((*lst_b)->next
			&& ft_int(ft_lstlast(*lst_b)) + 1 == ft_int(*lst_a)))
		ft_strlcpy(op_b, "rrb", 4);
	else if (pos || ((*lst_b)->next
			&& ft_int((*lst_b)->next) + 1 == ft_int(*lst_a)))
		ft_strlcpy(op_b, "rb", 3);
	else if (!pos && ft_int(tmp) < ft_int(*lst_a))
		return (ft_strlcpy(op_b, "pa", 3), lst_b_size - 1);
	return (lst_b_size);
}

static void	ft_fill_a(char *op_a, t_list **lst_a, char *op_b, t_list **lst_b)
{
	const int	size = ft_lstsize(*lst_a) + ft_lstsize(*lst_b);
	int			lst_b_size;
	int			min;
	t_list		*tmp;

	lst_b_size = ft_lstsize(*lst_b);
	min = lst_b_size - size / BRACKETS;
	while (lst_b_size > min && lst_b_size > 0)
	{
		ft_strlcpy(op_a, "", 1);
		lst_b_size = ft_sort_b(min, lst_a, op_b, lst_b);
		if (ft_strncmp(op_b, "pa", 3))
		{
			tmp = *lst_a;
			while (ft_int(tmp) < size && tmp->next
				&& ft_int(tmp) + 1 == ft_int(tmp->next))
				tmp = tmp->next;
			if (tmp && ft_int(tmp) < size)
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
	int		pos;
	t_list	*tmp;

	if (ft_is_sorted(lst_a))
		return ;
	lst_b = NULL;
	ft_fill_b(op_a, &lst_a, op_b, &lst_b);
	ft_sort_a(&lst_a, &lst_b);
	while (lst_b)
		ft_fill_a(op_a, &lst_a, op_b, &lst_b);
	tmp = lst_a;
	pos = 0;
	while (ft_int(tmp) != 1 && (++pos))
		tmp = tmp->next;
	ft_strlcpy(op_a, "ra", 3);
	if (pos > ft_lstsize(lst_a) / 2)
		ft_strlcpy(op_a, "rra", 4);
	while (!ft_is_sorted(lst_a))
		ft_operate(op_a, &lst_a, "", &lst_b);
}
