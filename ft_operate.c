/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:34:50 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/14 12:50:14 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_operate_b(t_stack *stck, uint8_t print)
{
	if (!ft_strncmp(stck->ops + 4, "rrb", 4))
	{
		(ft_reverse_rotate(&(stck->b)), ++(stck->score));
		if (print)
			ft_printf("rrb\n");
	}
	else if (!ft_strncmp(stck->ops + 4, "rb", 3))
	{
		(ft_rotate(&(stck->b)), ++(stck->score));
		if (print)
			ft_printf("rb\n");
	}
	else if (!ft_strncmp(stck->ops + 4, "sb", 3))
	{
		(ft_swap(&(stck->b)), ++(stck->score));
		if (print)
			ft_printf("sb\n");
	}
	else if (!ft_strncmp(stck->ops + 4, "pa", 3))
	{
		(ft_push(&(stck->a), &(stck->b)), ++(stck->score));
		if (print)
			ft_printf("pa\n");
	}
}

static void	ft_operate_a(t_stack *stck, uint8_t print)
{
	if (!ft_strncmp(stck->ops, "rra", 4))
	{
		(ft_reverse_rotate(&(stck->a)), ++(stck->score));
		if (print)
			ft_printf("rra\n");
	}
	else if (!ft_strncmp(stck->ops, "ra", 3))
	{
		(ft_rotate(&(stck->a)), ++(stck->score));
		if (print)
			ft_printf("ra\n");
	}
	else if (!ft_strncmp(stck->ops, "sa", 3))
	{
		(ft_swap(&(stck->a)), ++(stck->score));
		if (print)
			ft_printf("sa\n");
	}
	else if (!ft_strncmp(stck->ops, "pb", 3))
	{
		(ft_push(&(stck->b), &(stck->a)), ++(stck->score));
		if (print)
			ft_printf("pb\n");
	}
}

void	ft_operate(t_stack *stck, uint8_t print)
{
	if (!ft_strncmp(stck->ops, "rra", 4)
		&& !ft_strncmp(stck->ops + 4, "rrb", 4))
	{
		(ft_reverse_rotate(&(stck->a)), ft_reverse_rotate(&(stck->b)));
		++(stck->score);
		if (print)
			ft_printf("rrr\n");
	}
	else if (!ft_strncmp(stck->ops, "ra", 3)
		&& !ft_strncmp(stck->ops + 4, "rb", 3))
	{
		(ft_rotate(&(stck->a)), ft_rotate(&(stck->b)), ++(stck->score));
		if (print)
			ft_printf("rr\n");
	}
	else if (!ft_strncmp(stck->ops, "sa", 3)
		&& !ft_strncmp(stck->ops + 4, "sb", 3) && (++(stck->score)))
	{
		(ft_swap(&(stck->a)), ft_swap(&(stck->b)), ++(stck->score));
		if (print)
			ft_printf("ss\n");
	}
	else
		(ft_operate_b(stck, print), ft_operate_a(stck, print));
}
