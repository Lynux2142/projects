/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:58:30 by lguiller          #+#    #+#             */
/*   Updated: 2018/01/06 10:39:09 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	if (size == 0)
		return (ft_strlen((char *)src));
	j = 0;
	while (dst[j] && j < size)
		++j;
	if (j == size)
		return (ft_strlen(src) + size);
	i = 0;
	while (src[i] && ((j + i) < (size - 1)))
	{
		dst[j + i] = src[i];
		++i;
	}
	dst[j + i] = '\0';
	return (ft_strlen((char *)src) + j);
}