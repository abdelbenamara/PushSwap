/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:17 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/11 15:58:34 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"

# ifndef BRACKETS
#  define BRACKETS	4
# endif

long	ft_atol(const char *nptr);
int		ft_int(t_list *lst);
uint8_t	ft_check(const char *str, long nb, t_list *lst);
t_list	*ft_normalize(t_list *lst, int *tab, int size);

void	ft_swap(t_list **lst);
void	ft_push(t_list **lst_dst, t_list **lst_src);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);

uint8_t	ft_is_sorted(t_list *lst);
void	ft_operate(char *op_a, t_list **lst_a, char *op_b, t_list **lst_b);
void	ft_sort(t_list *lst_a);

#endif
