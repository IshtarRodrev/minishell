/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:33:25 by akechedz          #+#    #+#             */
/*   Updated: 2026/08/18 19:52:31 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef MINISHELL_H
# define MINISHELL_H
# include "libft/libft.h"

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_expr   t_expr;
typedef struct s_cmd    t_cmd;
typedef struct s_pipe   t_pipe;
typedef struct s_brac   t_brac;

typedef enum e_type
{
	CMD,
	PIPE,
	OP,
	BRC
}	t_type;

typedef struct s_minishell
{
	char				**envp;
	pid_t			*pids;
	t_expr			*tree_root_unit;
}	t_minishell;


typedef struct s_oprt
{
	char			type;
	struct s_expr	*right;
	struct s_expr	*left;
}	t_oprt;

typedef struct s_expr
{
	t_type			type; //TODO: Eventually enum data type: CMD/PIPE/OP/BRAC
	union
	{
		t_cmd  *cmd;
		t_pipe *pipe;
		t_oprt *oprt;
		t_brac *brac;
	};
}	t_expr;

typedef struct s_pipe
{
	struct s_cmd	**commands;
}	t_pipe;

typedef struct s_cmd
{
	char			*text;
	char			*suffix;
}	t_cmd;

typedef struct s_brac
{
	struct s_expr	*expr;
}	t_brac;

extern volatile sig_atomic_t	the_signal;

/* ************************************************************************** */
/*                                   EXECUTION                                 */
/* ************************************************************************** */
typedef struct s_exec_cmd
{
	char	**argv;
}	t_exec_cmd;

typedef struct s_shell
{
	char	**env;
	int		exit_status;
}	t_shell;

int		execute_command(t_exec_cmd *cmd, t_shell *shell);
char	*get_path_env(char **envp);
void    free_split(char **arr);
char	*get_command_path(char *cmd, char **envp);
int		is_builtin(char *cmd);
int		builtin_pwd(void);
int		builtin_echo(t_exec_cmd *cmd);
int		builtin_exit(t_exec_cmd *cmd);
char	**copy_env(char **envp);
int		builtin_env(t_shell *shell);
int		builtin_cd(t_exec_cmd *cmd, t_shell *shell);
int		set_existing_var(char **env, char *name, char *value);
char	*get_name(char *arg);
char	*get_value(char *arg);
char	**add_env_var(char **env, char *new_entry);
int		builtin_export(t_exec_cmd *cmd, t_shell *shell);
int		builtin_unset(t_exec_cmd *cmd, t_shell *shell);

#endif
