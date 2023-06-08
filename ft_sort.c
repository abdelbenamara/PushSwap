/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:38:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/08 16:47:18 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static uint8_t	ft_is_sorted(t_list *lst)
{
	int	prev;

	prev = ft_int(lst);
	lst = lst->next;
	while (lst)
	{
		if (prev > ft_int(lst))
			return (0);
		prev = ft_int(lst);
		lst = lst->next;
	}
	return (1);
}

static void	ft_optimized_rotate(t_list **lst_a, int max, char *op_a)
{
	int		pos;
	int		i;
	t_list	*tmp;

	pos = 0;
	tmp = *lst_a;
	while (ft_int(tmp) > max && (++pos))
		tmp = tmp->next;
	i = 1;
	tmp = (*lst_a)->next;
	while (tmp)
	{
		if (++i && ft_int(tmp) <= max && ft_lstsize(*lst_a) - i < pos)
				pos = i;
		tmp = tmp->next;
	}
	if (!pos)
		ft_strlcpy(op_a, "pb", 3);
	else if (pos > ft_lstsize(*lst_a) / 2)
		ft_strlcpy(op_a, "rra", 4);
	else
		ft_strlcpy(op_a, "ra", 3);
}

static void	ft_clear(char *op_a, t_list **lst_a, char *op_b, t_list **lst_b)
{
	int		max;

	max = 0;
	while (ft_lstsize(*lst_a) > 3)
	{
		if (ft_lstsize(*lst_b) == max)
			max += (ft_lstsize(*lst_a) + ft_lstsize(*lst_b)) / 10;
		if (max < 3 || max > ft_lstsize(*lst_a) + ft_lstsize(*lst_b) - 3)
			max = ft_lstsize(*lst_a) + ft_lstsize(*lst_b) - 3;
		ft_strlcpy(op_a, "", 1);
		ft_strlcpy(op_b, "", 1);
		if (*lst_b && (*lst_b)->next)
		{
			if (ft_int(*lst_b) < ft_int(ft_lstlast(*lst_b))
				&& ft_int(*lst_b) > ft_int((*lst_b)->next))
				ft_strlcpy(op_b, "rrb", 4);
			else if (ft_int(*lst_b) < ft_int(ft_lstlast(*lst_b)))
				ft_strlcpy(op_b, "rb", 3);
		}
		ft_optimized_rotate(lst_a, max, op_a);
		ft_operate(op_a, lst_a, op_b, lst_b);
	}
}

static void	ft_mini_sort(char *op_a, t_list *lst_a, char *op_b, t_list *lst_b)
{
	while (!ft_is_sorted(lst_a))
	{
		ft_strlcpy(op_a, "", 1);
		ft_strlcpy(op_b, "", 1);
		if (lst_b && lst_b->next)
		{
			if (ft_int(lst_b) < ft_int(ft_lstlast(lst_b))
				&& ft_int(lst_b) > ft_int(lst_b->next))
				ft_strlcpy(op_b, "rrb", 4);
			else if (ft_int(lst_b) < ft_int(ft_lstlast(lst_b)))
				ft_strlcpy(op_b, "rb", 3);
		}
		if (ft_int(ft_lstlast(lst_a)) < ft_int(lst_a)
			&& ft_int(lst_a) < ft_int(lst_a->next))
			ft_strlcpy(op_a, "rra", 4);
		else if (ft_int(lst_a) > ft_int(ft_lstlast(lst_a))
			&& ft_int(lst_a) > ft_int(lst_a->next))
			ft_strlcpy(op_a, "ra", 3);
		else if (ft_int(lst_a) > ft_int(lst_a->next)
			|| ft_int(lst_a->next) > ft_int(ft_lstlast(lst_a)))
			ft_strlcpy(op_a, "sa", 3);
		ft_operate(op_a, &lst_a, op_b, &lst_b);
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
	ft_clear(op_a, &lst_a, op_b, &lst_b);
	ft_mini_sort(op_a, lst_a, op_b, lst_b);
	while (lst_b)
	{
		pos = 0;
		tmp = lst_b;
		while (ft_int(tmp) != ft_lstsize(lst_b) && (++pos))
			tmp = tmp->next;
		if (!pos)
			ft_operate("", &lst_a, "pa", &lst_b);
		else if (pos > ft_lstsize(lst_b) / 2)
			ft_operate("", &lst_a, "rrb", &lst_b);
		else if (pos)
			ft_operate("", &lst_a, "rb", &lst_b);
	}
}
