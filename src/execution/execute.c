/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:36:45 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/07/24 17:50:08 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	execute_command(t_cmd *cmd, char **envp)
{
	pid_t	pid;
    int status;

	pid = fork();
    if (pid == 0)
    {
        execve(cmd->argv[0], cmd->argv, envp);
        printf("execve failed\n");
        exit(127);
    }
    else
    {
        waitpid(pid, &status, 0);
        printf("child exited with %d\n", WEXITSTATUS(status));
    }
       return (WEXITSTATUS(status));
}