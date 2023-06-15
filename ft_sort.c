/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 10:38:48 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/15 21:44:03 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_fill_b(t_stack *stck, int size, int parts, uint8_t print)
{
	int			lst_a_size;
	int			lst_b_size;
	int			max;

	lst_a_size = size;
	lst_b_size = size - lst_a_size;
	max = 0;
	stck->b = NULL;
	stck->score = 0;
	while (lst_a_size > 3)
	{
		if (lst_b_size == max)
			max += lst_a_size / (parts - (lst_a_size < size / parts));
		if (lst_b_size == max || max < 3 || max > size - 3)
			max = size - 3;
		ft_strlcpy(stck->ops + 4, "", 1);
		if (stck->b && stck->b->next && (ft_int(stck->b) < max / 2
				|| ft_int(stck->b) < ft_int(ft_lstlast(stck->b))))
			ft_strlcpy(stck->ops + 4, "rb", 3);
		if (ft_int(stck->a) <= max && (++lst_b_size))
			(ft_strlcpy(stck->ops, "pb", 3), --lst_a_size);
		else
			ft_strlcpy(stck->ops, "ra", 3);
		ft_operate(stck, print);
	}
}

static void	ft_sort_a(t_stack *stck, uint8_t print)
{
	ft_strlcpy(stck->ops + 4, "", 1);
	while (!ft_is_sorted(stck->a))
	{
		if (ft_int(ft_lstlast(stck->a)) < ft_int(stck->a)
			&& ft_int(stck->a) < ft_int((stck->a)->next))
			(ft_strlcpy(stck->ops, "rra", 4), ft_operate(stck, print));
		else if (ft_int(stck->a) > ft_int(ft_lstlast(stck->a))
			&& ft_int(stck->a) > ft_int((stck->a)->next))
			(ft_strlcpy(stck->ops, "ra", 3), ft_operate(stck, print));
		else if (ft_int(stck->a) > ft_int((stck->a)->next)
			|| ft_int((stck->a)->next) > ft_int(ft_lstlast(stck->a)))
			(ft_strlcpy(stck->ops, "sa", 3), ft_operate(stck, print));
	}
}

static void	ft_sort_b(t_stack *stck, int size, int min, int *lst_b_size)
{
	int			pos;
	t_list		*tmp;

	pos = 0;
	tmp = stck->b;
	ft_strlcpy(stck->ops + 4, "", 1);
	while (tmp && (ft_int(tmp) <= min || (ft_int(ft_lstlast(stck->a)) != size
				&& ft_int(tmp) < ft_int(ft_lstlast(stck->a)))) && (++pos))
		tmp = tmp->next;
	if (!tmp || ft_int(stck->b) - 1 == ft_int(stck->a))
		return ;
	else if (pos > (*lst_b_size) / 2 || (stck->b->next
			&& ft_int(ft_lstlast(stck->b)) + 1 == ft_int(stck->a)))
		ft_strlcpy(stck->ops + 4, "rrb", 4);
	else if (pos || (stck->b->next
			&& ft_int(stck->b->next) + 1 == ft_int(stck->a)))
		ft_strlcpy(stck->ops + 4, "rb", 3);
	else if (!pos && ft_int(tmp) < ft_int(stck->a))
		(ft_strlcpy(stck->ops + 4, "pa", 3), --(*lst_b_size));
}

static void	ft_fill_a(t_stack *stck, int size, int parts, uint8_t print)
{
	int		lst_b_size;
	int		min;
	t_list	*tmp;

	lst_b_size = size - ft_lstsize(stck->a);
	min = lst_b_size - size / parts;
	while (lst_b_size > min && lst_b_size > 0)
	{
		ft_strlcpy(stck->ops, "", 1);
		ft_sort_b(stck, size, min, &lst_b_size);
		if (ft_strncmp(stck->ops + 4, "pa", 3))
		{
			tmp = stck->a;
			while (ft_int(tmp) < size && tmp->next
				&& ft_int(tmp) + 1 == ft_int(tmp->next))
				tmp = tmp->next;
			if (tmp && ft_int(tmp) < size)
				ft_strlcpy(stck->ops, "ra", 3);
			else if (ft_int(ft_lstlast(stck->a)) + 1 == ft_int(stck->a))
				ft_strlcpy(stck->ops, "rra", 4);
		}
		ft_operate(stck, print);
	}
}

int	ft_sort(t_list *lst_a, int size, int parts, uint8_t print)
{
	t_stack	*stck;
	int		pos;
	t_list	*tmp;

	if (ft_is_sorted(lst_a))
		return (ft_lstclear(&lst_a, &free), 0);
	stck = malloc(sizeof(t_stack));
	if (!stck)
		return (-1);
	stck->a = lst_a;
	ft_fill_b(stck, size, parts, print);
	ft_sort_a(stck, print);
	while (stck->b)
		ft_fill_a(stck, size, parts, print);
	pos = 0;
	tmp = stck->a;
	while (ft_int(tmp) != 1 && (++pos))
		tmp = tmp->next;
	(ft_strlcpy(stck->ops, "ra", 3), ft_strlcpy(stck->ops + 4, "", 1));
	if (pos > ft_lstsize(stck->a) / 2)
		ft_strlcpy(stck->ops, "rra", 4);
	while (!ft_is_sorted(stck->a))
		ft_operate(stck, print);
	pos = stck->score;
	return (ft_lstclear(&(stck->a), &free), free(stck), pos);
}
