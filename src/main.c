/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:16:23 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/08/18 19:53:27 by farhanmasfi      ###   ########.fr       */
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

	(void)argc;
	(void)argv;
	shell.env = copy_env(envp);
	shell.exit_status = 0;
	cmd.argv = malloc(sizeof(char *) * 3);
	cmd.argv[0] = "export";
	cmd.argv[1] = "MYVAR=hello";
	cmd.argv[2] = NULL;
	execute_command(&cmd, &shell);
	cmd.argv[0] = "unset";
	cmd.argv[1] = "MYVAR";
	cmd.argv[2] = NULL;
	execute_command(&cmd, &shell);
	cmd.argv[0] = "env";
	cmd.argv[1] = NULL;
	execute_command(&cmd, &shell);
	free(cmd.argv);
	return (0);
}