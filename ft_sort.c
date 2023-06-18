/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:38:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/18 11:42:03 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_b(t_stack *stck, int size, int splits)
{
	int	a_size;
	int	b_size;
	int	max;

	a_size = size;
	b_size = size - a_size;
	max = 0;
	stck->b = NULL;
	while (a_size > 3)
	{
		if (b_size == max)
			max += a_size / (splits - (a_size < size / splits));
		if (b_size == max || max < 3 || max > size - 3)
			max = size - 3;
		ft_strlcpy(stck->op_b, "", 1);
		if (stck->b && stck->b->next
			&& (ft_int(stck->b) < (max + b_size) / 2
				|| ft_int(stck->b) < ft_int(ft_lstlast(stck->b))))
			ft_strlcpy(stck->op_b, "rb", 3);
		if (ft_int(stck->a) <= max && (++b_size))
			(ft_strlcpy(stck->op_a, "pb", 3), --a_size);
		else
			ft_strlcpy(stck->op_a, "ra", 3);
		ft_operate(stck);
	}
}

static void	ft_sort_a(t_stack *stck)
{
	ft_strlcpy(stck->op_b, "", 1);
	while (!ft_is_sorted(stck->a))
	{
		if (ft_int(ft_lstlast(stck->a)) < ft_int(stck->a)
			&& ft_int(stck->a) < ft_int((stck->a)->next))
			(ft_strlcpy(stck->op_a, "rra", 4), ft_operate(stck));
		else if (ft_int(stck->a) > ft_int(ft_lstlast(stck->a))
			&& ft_int(stck->a) > ft_int((stck->a)->next))
			(ft_strlcpy(stck->op_a, "ra", 3), ft_operate(stck));
		else if (ft_int(stck->a) > ft_int((stck->a)->next)
			|| ft_int((stck->a)->next) > ft_int(ft_lstlast(stck->a)))
			(ft_strlcpy(stck->op_a, "sa", 3), ft_operate(stck));
	}
}

static void	ft_sort_b(t_stack *stck, int size, int min, int *b_size)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = stck->b;
	ft_strlcpy(stck->op_b, "", 1);
	while (tmp
		&& (ft_int(tmp) <= min
			|| (ft_int(ft_lstlast(stck->a)) != size
				&& ft_int(tmp) < ft_int(ft_lstlast(stck->a))))
		&& (++pos))
		tmp = tmp->next;
	if (!tmp || ft_int(stck->b) - 1 == ft_int(stck->a))
		return ;
	else if (pos > (*b_size) / 2
		|| (stck->b->next
			&& ft_int(ft_lstlast(stck->b)) + 1 == ft_int(stck->a)))
		ft_strlcpy(stck->op_b, "rrb", 4);
	else if (pos
		|| (stck->b->next
			&& ft_int(stck->b->next) + 1 == ft_int(stck->a)))
		ft_strlcpy(stck->op_b, "rb", 3);
	else if (!pos && ft_int(tmp) < ft_int(stck->a))
		(ft_strlcpy(stck->op_b, "pa", 3), --(*b_size));
}

static void	ft_fill_a(t_stack *stck, int size, int splits)
{
	int		b_size;
	int		min;
	t_list	*tmp;

	b_size = size - ft_lstsize(stck->a);
	min = b_size - size / splits;
	while (b_size > min && b_size > 0)
	{
		ft_strlcpy(stck->op_a, "", 1);
		ft_sort_b(stck, size, min, &b_size);
		if (ft_strncmp(stck->op_b, "pa", 3))
		{
			tmp = stck->a;
			while (ft_int(tmp) < size
				&& tmp->next
				&& ft_int(tmp) + 1 == ft_int(tmp->next))
				tmp = tmp->next;
			if (tmp && ft_int(tmp) < size)
				ft_strlcpy(stck->op_a, "ra", 3);
			else if (ft_int(ft_lstlast(stck->a)) + 1 == ft_int(stck->a))
				ft_strlcpy(stck->op_a, "rra", 4);
		}
		ft_operate(stck);
	}
}

uint8_t	ft_sort(t_list *lst_a, int size, int splits)
{
	t_stack	*stck;
	int		pos;
	t_list	*tmp;

	if (ft_is_sorted(lst_a))
		return (ft_lstclear(&lst_a, &free), 1);
	stck = malloc(sizeof(t_stack));
	if (!stck)
		return (0);
	stck->a = lst_a;
	ft_fill_b(stck, size, splits);
	ft_sort_a(stck);
	while (stck->b)
		ft_fill_a(stck, size, splits);
	pos = 0;
	tmp = stck->a;
	while (ft_int(tmp) != 1 && (++pos))
		tmp = tmp->next;
	(ft_strlcpy(stck->op_a, "ra", 3), ft_strlcpy(stck->op_b, "", 1));
	if (pos > ft_lstsize(stck->a) / 2)
		ft_strlcpy(stck->op_a, "rra", 4);
	while (!ft_is_sorted(stck->a))
		ft_operate(stck);
	return (ft_lstclear(&(stck->a), &free), free(stck), 1);
}
