/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/15 18:22:04 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/08/15 20:29:11 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

char	**copy_env(char **envp)
{
	char	**env;
	int		count;
	int		i;

	count = 0;
	while (envp[count])
		count++;
	env = malloc(sizeof(char *) * (count + 1));
	i = 0;
	while (i < count)
	{
		env[i] = ft_strdup(envp[i]);
		i++;
	}
	env[i] = NULL;
	return (env);
}
int	set_existing_var(char **env, char *name, char *value)
{
	char	*entry;
	char	*tmp;
	int		i;
	int		len;

	tmp = ft_strjoin(name, "=");
	entry = ft_strjoin(tmp, value);
	free(tmp);
	len = ft_strlen(name);
	i = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], name, len) && env[i][len] == '=')
		{
			free(env[i]);
			env[i] = entry;
			return (1);
		}
		i++;
	}
	free(entry);
	return (0);
}
char	*get_name(char *arg)
{
	char	*eq;
	int		len;

	eq = ft_strchr(arg, '=');
	len = eq - arg;
	return (ft_substr(arg, 0, len));
}
char	*get_value(char *arg)
{
	char	*eq;

	eq = ft_strchr(arg, '=');
	return (ft_strdup(eq + 1));
}
char	**add_env_var(char **env, char *new_entry)
{
	char	**new_env;
	int		count;
	int		i;

	count = 0;
	while (env[count])
		count++;
	new_env = malloc(sizeof(char *) * (count + 2));
	i = 0;
	while (i < count)
	{
		new_env[i] = env[i];
		i++;
	}
	new_env[count] = new_entry;
	new_env[count + 1] = NULL;
	free(env);
	return (new_env);
}