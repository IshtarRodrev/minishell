/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:33:25 by akechedz          #+#    #+#             */
/*   Updated: 2026/08/04 22:48:31 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */

typedef struct s_opt
{
	char			*type;
	struct s_opt	*next;
}	t_opt;

typedef struct s_cmd
{
	char			*text;
	char			*suffix;
	struct s_cmd	*next;
}	t_cmd;

typedef struct s_pipe
{
	struct s_cmd	*right;
	struct s_cmd	*left;
	//struct s_pipe	*next;
}	t_pipe;

/* ************************************************************************** */
/*                                   EXECUTION                                 */
/* ************************************************************************** */

int	    execute_command(t_cmd *cmd, char **envp);
char	*get_path_env(char **envp);
void    free_split(char **arr);
char	*get_command_path(char *cmd, char **envp);

#endif
