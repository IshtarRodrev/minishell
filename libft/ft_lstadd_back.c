/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shoque <shoque@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 04:27:10 by shoque            #+#    #+#             */
/*   Updated: 2025/08/03 19:33:20 by shoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*help_me;

	if (!lst || !new)
		return ;
	help_me = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while (help_me->next != NULL)
		help_me = help_me->next;
	help_me->next = new;
}
