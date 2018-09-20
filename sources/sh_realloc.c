/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftait <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/01 15:53:00 by ftait             #+#    #+#             */
/*   Updated: 2017/10/01 15:53:37 by ftait            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*sh_realloc(char *str2)
{
	char	*nstr;

	if (str2 == NULL)
		return (NULL);
	nstr = (char *)malloc(sizeof(char) * ft_strlen(str2));
	ft_strcpy(nstr, str2);
	return (nstr);
}
