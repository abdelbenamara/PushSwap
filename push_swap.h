/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:17 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/13 23:11:25 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"

typedef struct s_stack
{
	t_list	*a;
	t_list	*b;
	char	ops[8];
	int		score;
}	t_stack;

long	ft_atol(const char *nptr);
int		ft_int(t_list *lst);
uint8_t	ft_check(const char *str, long nb, t_list *lst);

void	ft_swap(t_list **lst);
void	ft_push(t_list **lst_dst, t_list **lst_src);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);

uint8_t	ft_is_sorted(t_list *lst);
void	ft_operate(t_stack *stck, uint8_t print);
int		ft_sort(t_list *lst_a, int size, int parts, uint8_t print);

#endif
