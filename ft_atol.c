/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenamar <abenamar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 23:38:33 by abenamar          #+#    #+#             */
/*   Updated: 2023/05/10 01:08:10 by abenamar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *nptr)
{
	long	l;
	long	sign;

	while (*nptr == ' ' || (9 <= *nptr && *nptr <= 13))
		++nptr;
	l = 0;
	sign = 1;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign = -1;
		++nptr;
	}
	while (ft_isdigit(*nptr))
	{
		l = l * 10 + (*nptr - '0');
		++nptr;
	}
	return (sign * l);
}
