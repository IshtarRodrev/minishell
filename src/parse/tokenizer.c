#include "minishell.h"


/* ************************************************************************** */
/*                          MORE FUCKING STRUCTURES                           */
/* ************************************************************************** */

/* typedef struct s_token
{
    t_toktype   type;
    char        *value;     // only for WORD or redir target
}   t_token;

typedef struct s_toklist
{
    t_token     *tokens;
    size_t      size;
    size_t      capacity;
}   t_toklist; */

/* ************************************************************************** */
/*                          TOKEN LIST MANAGEMENT                             */
/* ************************************************************************** */

t_toklist *tok_new_list(void)
{
    t_toklist *lst;

    lst = malloc(sizeof(t_toklist));
    if (!lst)
        return (NULL);
    lst->arr = NULL;
    lst->size = 0;
    lst->cap = 0;
    return (lst);
}

void tok_grow(t_toklist *lst)
{
    size_t      newcap;
    t_token     *new;

    if (lst->cap == 0)
        newcap = 8;
    else
        newcap = lst->cap * 2;
    new = malloc(sizeof(t_token) * newcap);
    if (!new)
        return ;
    if (lst->arr)
        memcpy(new, lst->arr, sizeof(t_token) * lst->size);
    free(lst->arr);
    lst->arr = new;
    lst->cap = newcap;
}

void	tok_push(t_toklist *lst, t_toktype type, char *value)
{
    if (lst->size == lst->cap)
        tok_grow(lst);
    lst->arr[lst->size].type = type;
    lst->arr[lst->size].value = value;
    lst->size++;
}

/* ************************************************************************** */
/*                              MATCHING HELPERS                              */
/* ************************************************************************** */

int tok_match(const char *s, size_t i, const char *pat)
{
    size_t j;

    j = 0;
    while (pat[j])
    {
        if (s[i + j] != pat[j])
            return (0);
        j++;
    }
    return (1);
}

int is_special(char c)
{
    if (c == '|' || c == '&' || c == '(' || c == ')' || c == '"')
        return (1);
    if (c == '\'' || c == '<' || c == '>' || c == ' ' || c == '\t')
        return (1);
    return (0);
}

/* ************************************************************************** */
/*                              TOKEN READERS                                 */
/* ************************************************************************** */

size_t read_word(const char *s, size_t i, t_toklist *lst)
{
    size_t start;

    start = i;
    while (s[i] && !is_special(s[i]))
    {
        i++;
    }
    return (tok_push(lst, TOK_WORD, strndup(s + start, i - start)), i);
}

size_t read_double_ops(const char *s, size_t i, t_toklist *lst)
{
	if (tok_match(s, i, "&&"))
		return (tok_push(lst, TOK_AND, NULL), i + 2);
	if (tok_match(s, i, "||"))
		return (tok_push(lst, TOK_OR, NULL), i + 2);
	if (tok_match(s, i, ">>"))
		return (tok_push(lst, TOK_REDIR_APPEND, NULL), i + 2);
	if (tok_match(s, i, "<<"))
		return (tok_push(lst, TOK_HEREDOC, NULL), i + 2);
	return (i);
}

size_t read_single_ops(const char *s, size_t i, t_toklist *lst)
{
	if (s[i] == '|')
		return (tok_push(lst, TOK_PIPE, NULL), i + 1);
	if (s[i] == '(')
		return (tok_push(lst, TOK_LPAREN, NULL), i + 1);
	if (s[i] == ')')
		return (tok_push(lst, TOK_RPAREN, NULL), i + 1);
	if (s[i] == '<')
		return (tok_push(lst, TOK_REDIR_IN, NULL), i + 1);
	if (s[i] == '>')
		return (tok_push(lst, TOK_REDIR_OUT, NULL), i + 1);
	return (i);
}

size_t read_operator(const char *s, size_t i, t_toklist *lst)
{
    size_t new_i;

    new_i = read_double_ops(s, i, lst);
    if (new_i != i)
        return (new_i);
    return (read_single_ops(s, i, lst));
}

/* ************************************************************************** */
/*                                TOKENIZER                                    */
/* ************************************************************************** */

t_toklist *ft_tokenize(char *s)
{
    t_toklist   *lst;
    size_t      i;

    lst = tok_new_list();
    if (!lst)
        return (NULL);
    i = 0;
    while (i < strlen(s))
    {
        while (s[i] == ' ' || s[i] == '\t')
            i++;
        if (i >= strlen(s))
            break;
        if (is_special(s[i]))
            i = read_operator(s, i, lst);
        else
            i = read_word(s, i, lst);
    }
    tok_push(lst, TOK_END, NULL);
    return (lst);
}
