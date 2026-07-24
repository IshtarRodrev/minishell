/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: farhanmasfickhoque <farhanmasfickhoque@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/24 16:02:10 by farhanmasfi       #+#    #+#             */
/*   Updated: 2026/07/24 17:34:45 by farhanmasfi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    char *args[] = {"/bin/ls", "-l", NULL};
	pid_t	pid;
    int status;

	pid = fork();
    if (pid == 0)
    {
       execve("/bin/ls", args, NULL);
       printf("execve failed\n");
        exit(127);
    }
    else
    {
        waitpid(pid, &status, 0);
        printf("child exited with %d\n", WEXITSTATUS(status));
    }
       return (0);
}