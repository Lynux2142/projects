/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/08 18:48:25 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/09 09:34:02 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int temp;
	int *swap;

	swap = &temp;
	temp = *b;
	*b = *a;
	*a = *swap;
}