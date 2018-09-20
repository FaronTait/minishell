/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:51:53 by ftait             #+#    #+#             */
/*   Updated: 2017/10/01 15:51:54 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		ft_env(char **env)
{
	while (*env != NULL)
	{
		ft_putstr(*env);
		write(1, "\n", 1);
		env++;
	}
	return (1);
}

int		ft_env_loop(char **env, t_data *p)
{
	int i;

	i = 0;
	while (env[i])
		i++;
	p->g_env = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		p->g_env[i] = ft_strdup(env[i]);
		i++;
	}
	return (1);
}
