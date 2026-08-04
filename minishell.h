/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:33:25 by akechedz          #+#    #+#             */
/*   Updated: 2026/07/27 14:54:40 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */

typedef struct s_cmd
{
	char			**argv;
	struct s_cmd	*next;
}	t_cmd;

/* ************************************************************************** */
/*                                   EXECUTION                                 */
/* ************************************************************************** */

int	    execute_command(t_cmd *cmd, char **envp);
char	*get_path_env(char **envp);
void    free_split(char **arr);
char	*get_command_path(char *cmd, char **envp);

#endif
