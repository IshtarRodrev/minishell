/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:16:23 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/08/18 20:33:55 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../minishell.h"

volatile sig_atomic_t	the_signal = 0;
int	main(int argc, char **argv, char **envp)
{
	t_shell		shell;
	t_exec_cmd	cmd;
	t_pipeline	pl;
	char		*line;

	(void)argc;
	(void)argv;
	shell.env = copy_env(envp);
	shell.exit_status = 0;
	while (1)
	{
		line = readline("minishell$ ");
		if (!line)
			break ;
		if (*line)
			add_history(line);
		pl = parse_pipeline(line);
		if (pl.count == 1)
		{
			cmd.argv = pl.cmds[0];
			execute_command(&cmd, &shell);
		}
		else if (pl.count == 2)
			run_two(&pl, &shell);
		free_pipeline(&pl);
		free(line);
	}
	return (0);
}