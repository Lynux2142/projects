/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manki <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 14:27:04 by manki             #+#    #+#             */
/*   Updated: 2017/12/27 11:36:56 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int		i;

	i = 0;
	if (nb > 0 && nb <= 2147395600)
		while (i * i < nb)
			i++;
	return (i);
}