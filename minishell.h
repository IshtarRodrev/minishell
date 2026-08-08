/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:33:25 by akechedz          #+#    #+#             */
/*   Updated: 2026/08/08 21:28:23 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */
/*                                   PARSING                                  */
/* ************************************************************************** */
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_opt
{
	char			*type;
	struct s_expr	*right;
	struct s_expr	*left;
}	t_opt;

typedef struct s_expr
{
	char			*type; //TODO: Eventually enum data type: CMD/PIPE/OP/BRAC
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

int	execute_command(t_cmd *cmd, char **envp);

#endif
