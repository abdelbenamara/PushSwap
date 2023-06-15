/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:23 by abenamar          #+#    #+#             */
/*   Updated: 2023/06/15 00:45:14 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft.h"
# include "limits.h"

long	ft_atol(const char *nptr);
int		ft_int(t_list *lst);
uint8_t	ft_check(const char *str, long nb, t_list *lst);

void	ft_swap(t_list **lst);
void	ft_push(t_list **lst_dst, t_list **lst_src);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);

uint8_t	ft_is_sorted(t_list *lst);

#endif
