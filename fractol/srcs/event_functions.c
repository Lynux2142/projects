/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 12:53:32 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/13 14:30:21 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

static void	ft_reset_fract(t_shape *shape)
{
	shape->zoom = 250.0;
	ft_set_values(shape);
}

int			ft_var_julia(int x, int y, t_shape *ptr)
{
	ptr->c_r = (double)x / (ptr->img_x / (ptr->x2 - ptr->x1)) + ptr->x1;
	ptr->c_i = (double)y / (ptr->img_y / (ptr->y2 - ptr->y1)) + ptr->y1;
	ft_display(ptr);
	return (0);
}

int			ft_key_funct(int key, t_shape *shape)
{
	if (key == 12)
		shape->iter += 10.0;
	if (key == 13)
		shape->iter -= 10.0;
	if (key == 49)
		ft_reset_fract(shape);
	if (key == 53)
		exit(0);
	ft_display(shape);
	return (0);
}

int			ft_mouse_funct(int mouse, int x, int y, t_shape *shape)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = (double)x / (shape->img_x / (shape->x2 - shape->x1)) + shape->x1;
	mouse_im = (double)y / (shape->img_y / (shape->y2 - shape->y1)) + shape->y1;
	if (mouse == 1 || mouse == 5)
	{
		shape->iter += 5.0;
		shape->zoom *= 1.5;
		shape->in_out = mouse;
		apply_zoom(shape, mouse_re, mouse_im, 1.5);
	}
	if (mouse == 4 || mouse == 2)
	{
		shape->iter -= 5.0;
		shape->zoom /= 1.5;
		shape->in_out = mouse;
		apply_zoom(shape, mouse_re, mouse_im, 1.5);
	}
	ft_display(shape);
	return (0);
}
