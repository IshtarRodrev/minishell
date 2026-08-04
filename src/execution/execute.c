/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:36:45 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/07/30 19:52:56 by farhanmasfi      ###   ########.fr       */
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
	int		status;
	char	*path;

	path = get_command_path(cmd->argv[0], envp);
	if (!path)
	{
		printf("command not found: %s\n", cmd->argv[0]);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		execve(path, cmd->argv, envp);
		printf("execve failed\n");
		exit(127);
	}
	free(path);
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

char	*get_path_env(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}
char	*get_command_path(char *cmd, char **envp)
{
	char	**dirs;
	int		i;
	char	*tmp;
	char	*candidate;

	if (ft_strchr(cmd, '/'))
		return (ft_strdup(cmd));
	dirs = ft_split(get_path_env(envp), ':');
	i = 0;
	while (dirs[i])
	{
		tmp = ft_strjoin(dirs[i], "/");
		candidate = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(candidate, X_OK) == 0)
		{
			free_split(dirs);
			return (candidate);
		}
		free(candidate);
		i++;
	}
	free_split(dirs);
	return (NULL);
}
