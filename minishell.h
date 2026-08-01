/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:33:25 by akechedz          #+#    #+#             */
/*   Updated: 2026/07/29 17:41:30 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

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

int	execute_command(t_cmd *cmd, char **envp);

#endif
