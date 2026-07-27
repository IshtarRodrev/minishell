/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 19:31:06 by shoque            #+#    #+#             */
/*   Updated: 2025/08/08 16:31:55 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_digit(int n)
{
	int	count;

	count = (n <= 0);
	while (n != 0)
	{
		n = (n / 10);
		count++;
	}
	return (count);
}

static void	write_digits(char *str, long int nb, int *counter)
{
	while (nb > 0)
	{
		str[--(*counter)] = (nb % 10) + '0';
		nb = nb / 10;
	}
}

char	*ft_itoa(int n)
{
	int			counter;
	long int	nb;
	char		*str;

	nb = n;
	counter = ft_count_digit(n);
	str = malloc(sizeof(char) * (counter + 1));
	if (!str)
		return (NULL);
	str[counter] = '\0';
	if (nb == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (nb < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	write_digits(str, nb, &counter);
	return (str);
}
