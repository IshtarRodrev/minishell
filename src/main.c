/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akechedz <akechedz@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 18:16:23 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/08/18 18:43:33 by akechedz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	//get data from env
	//printf("%s\n", envp[1]);
	char *rl;
//	char *out;
	t_toklist *tokens;

    rl = readline("$ ");
//	out = ft_parse(rl);
	tokens = ft_tokenize(rl);
	debug_tokens(tokens);
	//TODO:	rl = "output data";
//    printf("%s\n", out);
    return (0);
}