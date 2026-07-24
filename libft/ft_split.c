/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 19:08:18 by shoque            #+#    #+#             */
/*   Updated: 2025/07/26 20:25:10 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_free_all(char **arr, int n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

static int	ft_fill_split(char **arr, char const *s, char c, int words)
{
	int	i;
	int	j;
	int	wlen;

	i = 0;
	j = 0;
	while (j < words)
	{
		while (s[i] == c)
			i++;
		wlen = ft_word_len(&s[i], c);
		arr[j] = ft_substr(s, i, wlen);
		if (!arr[j])
		{
			ft_free_all(arr, j);
			return (0);
		}
		i = i + wlen;
		j++;
	}
	arr[j] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	words = ft_words(s, c);
	arr = (char **)malloc((words + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	if (!ft_fill_split(arr, s, c, words))
		return (NULL);
	return (arr);
}
