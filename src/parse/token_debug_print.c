#include "minishell.h"

static const char *tok_name(t_toktype t)
{
    if (t == TOK_WORD) return "WORD";
    if (t == TOK_PIPE) return "PIPE";
    if (t == TOK_AND) return "AND";
    if (t == TOK_OR) return "OR";
    if (t == TOK_LPAREN) return "LPAREN";
    if (t == TOK_RPAREN) return "RPAREN";
    if (t == TOK_REDIR_IN) return "REDIR_IN";
    if (t == TOK_REDIR_OUT) return "REDIR_OUT";
    if (t == TOK_REDIR_APPEND) return "APPEND";
    if (t == TOK_HEREDOC) return "HEREDOC";
    return "END";
}

void debug_tokens(t_toklist *lst)
{
    size_t i;

    i = 0;
    while (i < lst->size)
    {
        printf("[%s]", tok_name(lst->arr[i].type));
        if (lst->arr[i].value)
            printf(" \"%s\"", lst->arr[i].value);
        printf("\n");
        i++;
    }
}
