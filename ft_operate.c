/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:34:50 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/16 00:41:09 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_operate_b(t_stack *stck)
{
	if (!ft_strncmp(stck->op_b, "rrb", 4))
		(ft_reverse_rotate(&(stck->b)), ft_printf("rrb\n"));
	else if (!ft_strncmp(stck->op_b, "rb", 3))
		(ft_rotate(&(stck->b)), ft_printf("rb\n"));
	else if (!ft_strncmp(stck->op_b, "sb", 3))
		(ft_swap(&(stck->b)), ft_printf("sb\n"));
	else if (!ft_strncmp(stck->op_b, "pa", 3))
		(ft_push(&(stck->a), &(stck->b)), ft_printf("pa\n"));
}

static void	ft_operate_a(t_stack *stck)
{
	if (!ft_strncmp(stck->op_a, "rra", 4))
		(ft_reverse_rotate(&(stck->a)), ft_printf("rra\n"));
	else if (!ft_strncmp(stck->op_a, "ra", 3))
		(ft_rotate(&(stck->a)), ft_printf("ra\n"));
	else if (!ft_strncmp(stck->op_a, "sa", 3))
		(ft_swap(&(stck->a)), ft_printf("sa\n"));
	else if (!ft_strncmp(stck->op_a, "pb", 3))
		(ft_push(&(stck->b), &(stck->a)), ft_printf("pb\n"));
}

void	ft_operate(t_stack *stck)
{
	if (!ft_strncmp(stck->op_a, "rra", 4)
		&& !ft_strncmp(stck->op_b, "rrb", 4))
		(ft_reverse_rotate(&(stck->a)), ft_reverse_rotate(&(stck->b)), \
		ft_printf("rrr\n"));
	else if (!ft_strncmp(stck->op_a, "ra", 3)
		&& !ft_strncmp(stck->op_b, "rb", 3))
		(ft_rotate(&(stck->a)), ft_rotate(&(stck->b)), \
		ft_printf("rr\n"));
	else if (!ft_strncmp(stck->op_a, "sa", 3)
		&& !ft_strncmp(stck->op_b, "sb", 3))
		(ft_swap(&(stck->a)), ft_swap(&(stck->b)), \
		ft_printf("ss\n"));
	else
		(ft_operate_b(stck), ft_operate_a(stck));
}
