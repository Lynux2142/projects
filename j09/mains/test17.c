/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test17.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/14 10:26:46 by lguiller          #+#    #+#             */
/*   Updated: 2017/07/14 10:48:01 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		ft_max(int *tab, int length);

int		main(void)
{
	int tab[5];

	tab[0] = 42;
	tab[1] = 2;
	tab[2] = 45;
	tab[3] = 4;
	tab[4] = 22;
	printf("%d", ft_max(tab, 5));
	return (0);
}
