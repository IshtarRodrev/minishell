/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:33:25 by akechedz          #+#    #+#             */
/*   Updated: 2026/08/12 18:23:42 by farhanmasfi      ###   ########.fr       */
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

typedef enum e_type
{
	CMD,
	PIPE,
	OP,
	BRC
}	t_type;

typedef struct s_minishell
{
	chr				**envp;
	pid_t			*pids;
	t_expr			*tree_root_unit
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
	union minishell
	{
		t_cmd		*cmd;
		t_pipe		*pipe;
		t_oprt		*oprt;
		t_brac		*brac;
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

volatile sig_atomic_t	the_signal = 0;

/* ************************************************************************** */
/*                                   EXECUTION                                 */
/* ************************************************************************** */

int	    execute_command(t_cmd *cmd, char **envp);
char	*get_path_env(char **envp);
void    free_split(char **arr);
char	*get_command_path(char *cmd, char **envp);

#endif
