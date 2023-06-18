/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:17 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/18 15:19:40 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "libft.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	char	op_a[4];
	char	op_b[4];
}	t_stack;

long	ft_atol(const char *nptr);
int		ft_int(t_list *lst);
uint8_t	ft_check(const char *str, long nb, t_list *lst);

void	ft_swap(t_list **lst);
void	ft_push(t_list **lst_dst, t_list **lst_src);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);

uint8_t	ft_is_sorted(t_list *lst);
void	ft_operate(t_stack *stck);
uint8_t	ft_sort(t_list *lst_a, int size, int splits);

#endif
