/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:17 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/12 17:29:42 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"

long	ft_atol(const char *nptr);
int		ft_int(t_list *lst);
uint8_t	ft_check(const char *str, long nb, t_list *lst);
int		ft_extremum(t_list *lst, uint8_t max);
uint8_t	ft_is_sorted(t_list *lst, uint8_t asc);

void	ft_swap(t_list **lst);
void	ft_push(t_list **lst1, t_list **lst2);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);

void	ft_sort(t_list **lst_a);

#endif
