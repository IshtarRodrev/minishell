/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 17:36:45 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/08/18 19:52:19 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int	execute_command(t_exec_cmd *cmd, t_shell *shell)
{
	pid_t	pid;
	int		status;
	char	*path;

	if (is_builtin(cmd->argv[0]))
	{
		if (!ft_strncmp(cmd->argv[0], "pwd", 4))
			return (builtin_pwd());
		if (!ft_strncmp(cmd->argv[0], "echo", 5))
			return (builtin_echo(cmd));
		if (!ft_strncmp(cmd->argv[0], "exit", 5))
			return (builtin_exit(cmd));
		if (!ft_strncmp(cmd->argv[0], "env", 4))
			return (builtin_env(shell));
		if (!ft_strncmp(cmd->argv[0], "cd", 3))
			return (builtin_cd(cmd, shell));
		if (!ft_strncmp(cmd->argv[0], "export", 7))
			return (builtin_export(cmd, shell));
		if (!ft_strncmp(cmd->argv[0], "unset", 6))
			return (builtin_unset(cmd, shell));
	}
	path = get_command_path(cmd->argv[0], shell->env);
	if (!path)
	{
		printf("command not found: %s\n", cmd->argv[0]);
		return (127);
	}
	pid = fork();
	if (pid == 0)
	{
		execve(path, cmd->argv, shell->env);
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
int	is_builtin(char *cmd)
{
	if (!ft_strncmp(cmd, "pwd", 4))
		return (1);
	if (!ft_strncmp(cmd, "echo", 5))
		return (1);
	if (!ft_strncmp(cmd, "exit", 5))
		return (1);
	if (!ft_strncmp(cmd, "env", 4))
		return (1);
	if (!ft_strncmp(cmd, "cd", 3))
		return (1);
	if (!ft_strncmp(cmd, "export", 7))
		return (1);
	if (!ft_strncmp(cmd, "unset", 6))
		return (1);
	return (0);
}
int	builtin_pwd(void)
{
	char	cwd[1024];

	if (getcwd(cwd, sizeof(cwd)))
	{
		printf("%s\n", cwd);
		return (0);
	}
	return (1);
}
int	builtin_echo(t_exec_cmd *cmd)
{
	int	i;
	int	newline;

	i = 1;
	newline = 1;
	if (cmd->argv[1] && !ft_strncmp(cmd->argv[1], "-n", 3))
	{
		newline = 0;
		i = 2;
	}
	while (cmd->argv[i])
	{
		printf("%s", cmd->argv[i]);
		if (cmd->argv[i + 1])
			printf(" ");
		i++;
	}
	if (newline)
		printf("\n");
	return (0);
}
int	builtin_exit(t_exec_cmd *cmd)
{
	int	code;

	code = 0;
	if (cmd->argv[1])
		code = ft_atoi(cmd->argv[1]);
	printf("exit\n");
	exit(code);
}
int	builtin_env(t_shell *shell)
{
	int	i;

	i = 0;
	while (shell->env[i])
	{
		printf("%s\n", shell->env[i]);
		i++;
	}
	return (0);
}
int	builtin_cd(t_exec_cmd *cmd, t_shell *shell)
{
	char	cwd[1024];

	if (!cmd->argv[1])
		return (1);
	if (chdir(cmd->argv[1]) != 0)
	{
		printf("cd: %s: No such file or directory\n", cmd->argv[1]);
		return (1);
	}
	if (getcwd(cwd, sizeof(cwd)))
		set_existing_var(shell->env, "PWD", cwd);
	return (0);
}
int	builtin_export(t_exec_cmd *cmd, t_shell *shell)
{
	char	*name;
	char	*value;

	if (!cmd->argv[1])
		return (0);
	name = get_name(cmd->argv[1]);
	value = get_value(cmd->argv[1]);
	if (!set_existing_var(shell->env, name, value))
		shell->env = add_env_var(shell->env, ft_strdup(cmd->argv[1]));
	free(name);
	free(value);
	return (0);
}
int	builtin_unset(t_exec_cmd *cmd, t_shell *shell)
{
	int	i;
	int	j;
	int	len;

	if (!cmd->argv[1])
		return (0);
	len = ft_strlen(cmd->argv[1]);
	i = 0;
	while (shell->env[i])
	{
		if (!ft_strncmp(shell->env[i], cmd->argv[1], len)
			&& shell->env[i][len] == '=')
		{
			free(shell->env[i]);
			j = i;
			while (shell->env[j])
			{
				shell->env[j] = shell->env[j + 1];
				j++;
			}
		}
		else
			i++;
	}
	return (0);
}