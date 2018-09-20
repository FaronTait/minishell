/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_increase_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:52:38 by ftait             #+#    #+#             */
/*   Updated: 2017/10/01 15:52:39 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char		**ft_arraydup(char **env)
{
	char	**dest;
	int		i;

	if (!(env))
		return (NULL);
	dest = NULL;
	i = 0;
	dest = ft_sstrnew(ft_sstrlen(env));
	while (env[i])
	{
		dest[i] = ft_strdup(env[i]);
		i++;
	}
	dest[i] = NULL;
	return (dest);
}

void		sh_increase_array(char *str, t_data *p)
{
	static int		count;
	char			**temp;

	count = 0;
	while (p->g_env[count])
		count++;
	temp = (char **)malloc(sizeof(char *) * (count + 2));
	count = 0;
	while (p->g_env[count])
	{
		temp[count] = ft_strdup(p->g_env[count]);
		count++;
	}
	temp[count] = ft_strdup(str);
	temp[count + 1] = NULL;
	ft_delarray(p->g_env);
	p->g_env = ft_arraydup(temp);
	ft_delarray(temp);
	count = 0;
}
