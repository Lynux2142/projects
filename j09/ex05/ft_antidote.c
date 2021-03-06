/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 08:19:30 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 08:31:18 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	if (i == j || i == k || j == k)
		return (-1);
	if ((i > j && i < k) || (i < j && i > k))
		return (i);
	if ((j > i && j < k) || (j < i && j > k))
		return (j);
	if ((k > i && k < j) || (k < i && k > j))
		return (k);
	return (-1);
}
