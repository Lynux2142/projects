/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 13:12:23 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/13 16:58:14 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_const_var_2(t_shape *shape, t_draw *draw, t_fract *f)
{
	f->c_r = shape->c_r;
	f->c_i = shape->c_i;
	f->z_r = (double)draw->x / (shape->zoom) + shape->x1;
	f->z_i = (double)draw->y / (shape->zoom) + shape->y1;
	f->i = 0.0;
}

void		fract2(t_shape *shape)
{
	t_fract	f;

	ft_init(shape, &f.draw);
	while (++f.draw.x < shape->img_x)
	{
		f.draw.y = -1;
		while (++f.draw.y < shape->img_y)
		{
			ft_const_var_2(shape, &f.draw, &f);
			while (((f.z_r * f.z_r) + (f.z_i * f.z_i)) < 4.0
					&& f.i < shape->iter)
			{
				f.draw.tmp = f.z_r;
				f.z_r = (f.z_r * f.z_r) - (f.z_i * f.z_i) + f.c_r;
				f.z_i = 2.0 * f.z_i * f.draw.tmp + f.c_i;
				f.i += 1.0;
			}
			if (f.i == shape->iter)
				fill_pixel(shape, f.draw.x, f.draw.y, 0x000000);
			else
				fill_pixel(shape, f.draw.x, f.draw.y,
						ft_couleur(255 - (int)(f.i * 255 * shape->iter), 255 -
			(int)(f.i * 255 * shape->iter), (int)(f.i * 255 * shape->iter)));
		}
	}
}
