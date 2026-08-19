/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 14:33:25 by akechedz          #+#    #+#             */
/*   Updated: 2026/08/18 18:36:00 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/* ************************************************************************** */
/*                                   INCLUDES                                 */
/* ************************************************************************** */

# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>

/* ************************************************************************** */
/*                                   TOKENIZER                                */
/* ************************************************************************** */

typedef enum e_toktype
{
    TOK_WORD,
    TOK_PIPE,
    TOK_AND,
    TOK_OR,
    TOK_LPAREN,
    TOK_RPAREN,
    TOK_REDIR_IN,
    TOK_REDIR_OUT,
    TOK_REDIR_APPEND,
    TOK_HEREDOC,
    TOK_END
}   t_toktype;

typedef struct s_token
{
    t_toktype   type;
    char        *value;
}   t_token;

typedef struct s_toklist
{
    t_token     *arr;
    size_t      size;
    size_t      cap;
}   t_toklist;

t_toklist   *ft_tokenize(char *s);
void        debug_tokens(t_toklist *lst);

/* ************************************************************************** */
/*                                   PARSER                                   */
/* ************************************************************************** */

typedef struct s_expr   t_expr;

typedef struct s_oprt
{
    char            type;
    t_expr          *left;
    t_expr          *right;
}   t_oprt;

typedef struct s_pipe
{
    t_expr          **commands;
}   t_pipe;

typedef struct s_cmd
{
    char            *text;
    char            *suffix;
}   t_cmd;

typedef struct s_brac
{
    t_expr          *expr;
}   t_brac;

typedef struct s_expr
{
    t_toktype       type;
    union
    {
        t_pipe      *pipe;
        t_oprt      *oprt;
        t_cmd       *cmd;
        t_brac      *brac;
    };
}   t_expr;

char        *ft_parse(char *prompt);

/* ************************************************************************** */
/*                                   EXECUTION                                */
/* ************************************************************************** */

typedef struct s_minishell
{
    char            **envp;
    pid_t           *pids;
    t_expr          *tree_root_unit;
}   t_minishell;

int execute_command(t_cmd *cmd, char **envp);

#endif
