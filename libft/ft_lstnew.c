/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 22:48:25 by shoque            #+#    #+#             */
/*   Updated: 2025/07/30 23:33:01 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*help_me;

	help_me = malloc(sizeof(t_list));
	if (!help_me)
		return (NULL);
	help_me->content = content;
	help_me->next = NULL;
	return (help_me);
}
