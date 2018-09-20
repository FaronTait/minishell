/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:52:49 by ftait             #+#    #+#             */
/*   Updated: 2017/10/01 15:52:50 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		sh_launch(char **args, char **envp)
{
	pid_t		pid;
	int			status;
	char		*tmp;

	pid = fork();
	if (pid == 0)
	{
		tmp = sh_path(envp, args);
		execve(tmp, args, envp);
		ft_putstr("zsh: command not found: ");
		ft_putstr(args[0]);
		ft_putstr("\n");
		free(tmp);
		exit(0);
	}
	else
		waitpid(pid, &status, WUNTRACED);
	return (1);
}
