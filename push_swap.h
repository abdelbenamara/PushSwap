/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:51:17 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/10 01:14:10 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "limits.h"

long	ft_atol(const char *nptr);
void	ft_swap(t_list **lst);
void	ft_push(t_list **lst, t_list *new);
void	ft_rotate(t_list **lst);
void	ft_reverse_rotate(t_list **lst);

#endif
