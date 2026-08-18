/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_stub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 20:14:46 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/08/18 20:22:00 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

t_pipeline	parse_pipeline(char *line)
{
	t_pipeline	pl;
	char		**cmd_strs;
	int			i;

	cmd_strs = ft_split(line, '|');
	pl.count = 0;
	while (cmd_strs[pl.count])
		pl.count++;
	pl.cmds = malloc(sizeof(char **) * (pl.count + 1));
	i = 0;
	while (i < pl.count)
	{
		pl.cmds[i] = ft_split(cmd_strs[i], ' ');
		i++;
	}
	pl.cmds[i] = NULL;
	free_split(cmd_strs);
	return (pl);
}
void	free_pipeline(t_pipeline *pl)
{
	int	i;

	i = 0;
	while (i < pl->count)
	{
		free_split(pl->cmds[i]);
		i++;
	}
	free(pl->cmds);
}