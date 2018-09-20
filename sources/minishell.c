/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 16:01:41 by ftait             #+#    #+#             */
/*   Updated: 2017/10/01 16:03:11 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	ft_delarray(char **array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		ft_strdel(&array[i]);
		i++;
	}
	free(array);
}

int		main(int argc, char **argv, char **env)
{
	t_data		p;
	char		*line;
	char		**arg;

	argv = NULL;
	argc = 1;
	ft_env_loop(env, &p);
	ft_putstr("********************************\e[0m\n");
	ft_putstr("*       PROJECT:minishell      *\e[0m\n");
	ft_putstr("*          USER: ftait         *\e[0m\n");
	ft_putstr("********************************\e[0m\n");
	while (argc)
	{
		ft_putstr("\033[33;36m");
		ft_putstr("minishell$>");
		if (get_next_line(0, &line) < 0)
			ft_putstr("error");
		arg = ft_split(line);
		ft_strdel(&line);
		argc = sh_execute(arg, &p);
		line = NULL;
		ft_delarray(arg);
	}
	ft_delarray(p.g_env);
	return (0);
}
