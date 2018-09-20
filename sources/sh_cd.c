/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:51:29 by ftait             #+#    #+#             */
/*   Updated: 2017/10/01 15:54:16 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int		sh_cd(char **argv)
{
	if (argv[1] == NULL || ft_strcmp("~", argv[1]) == 0)
	{
		if (chdir(HOME) != 0)
			ft_putstr("HOME");
	}
	else
	{
		if (chdir(argv[1]) != 0)
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putstr(argv[1]);
			ft_putstr("\n");
		}
	}
	return (1);
}
