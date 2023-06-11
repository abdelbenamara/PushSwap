/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/08 11:34:50 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/11 11:02:01 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_snapshot(t_list *lst_a, t_list *lst_b)
{
#ifdef SNAPSHOT
	while (lst_a)
		(ft_printf("%d ", ft_int(lst_a)), lst_a = lst_a->next);
	ft_printf("| ");
	while (lst_b)
		(ft_printf("%d ", ft_int(lst_b)), lst_b = lst_b->next);
	ft_printf("\n");
#else
	(void) lst_a;
	(void) lst_b;
#endif
}

static void	ft_operate_b(char *op_b, t_list **lst_a, t_list **lst_b)
{
	if (!ft_strncmp(op_b, "rrb", 4))
		(ft_reverse_rotate(lst_b), ft_printf("rrb\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_b, "rb", 3))
		(ft_rotate(lst_b), ft_printf("rb\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_b, "sb", 3))
		(ft_swap(lst_b), ft_printf("sb\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_b, "pa", 3))
		(ft_push(lst_a, lst_b), ft_printf("pa\n"),
			ft_snapshot(*lst_a, *lst_b));
}

static void	ft_operate_a(char *op_a, t_list **lst_a, t_list **lst_b)
{
	if (!ft_strncmp(op_a, "rra", 4))
		(ft_reverse_rotate(lst_a), ft_printf("rra\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_a, "ra", 3))
		(ft_rotate(lst_a), ft_printf("ra\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_a, "sa", 3))
		(ft_swap(lst_a), ft_printf("sa\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_a, "pb", 3))
		(ft_push(lst_b, lst_a), ft_printf("pb\n"),
			ft_snapshot(*lst_a, *lst_b));
}

void	ft_operate(char *op_a, t_list **lst_a, char *op_b, t_list **lst_b)
{
	if (!ft_strncmp(op_a, "rra", 4) && !ft_strncmp(op_b, "rrb", 4))
		(ft_reverse_rotate(lst_a), ft_reverse_rotate(lst_b), ft_printf("rrr\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_a, "ra", 3) && !ft_strncmp(op_b, "rb", 3))
		(ft_rotate(lst_a), ft_rotate(lst_b), ft_printf("rr\n"),
			ft_snapshot(*lst_a, *lst_b));
	else if (!ft_strncmp(op_a, "sa", 3) && !ft_strncmp(op_b, "sb", 3))
		(ft_swap(lst_a), ft_swap(lst_b), ft_printf("ss\n"),
			ft_snapshot(*lst_a, *lst_b));
	else
		(ft_operate_b(op_b, lst_a, lst_b), ft_operate_a(op_a, lst_a, lst_b));
}
