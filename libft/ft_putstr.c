/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 16:44:00 by lguiller          #+#    #+#             */
/*   Updated: 2017/11/15 17:57:57 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			ft_putchar(str[i]);
			++i;
		}
	}
}
