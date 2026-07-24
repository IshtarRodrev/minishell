/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 20:16:30 by shoque            #+#    #+#             */
/*   Updated: 2025/08/05 19:41:26 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (*str < '0' || *str > '9')
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10;
		result = result + (*str - '0');
		str++;
	}
	return (result * sign);
}
