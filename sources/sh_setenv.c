/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:54:00 by ftait             #+#    #+#             */
/*   Updated: 2017/10/01 15:54:01 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	sh_setenv(char *arg, t_data *p)
{
	if (arg == NULL)
		ft_putstr("setenv: not enough arguments.\n");
	else
		sh_increase_array(arg, p);
	return (1);
}
