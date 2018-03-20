/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_funct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lguiller <lguiller@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/16 12:40:46 by lguiller          #+#    #+#             */
/*   Updated: 2018/03/19 17:11:40 by lguiller         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_print_coord(int x, int y, t_shape *shape)
{
	char	reel[20];
	char	imag[20];
	double	mouse_re;
	double	mouse_im;

	mouse_re = (double)x / (shape->img_x / (shape->x2 - shape->x1)) + shape->x1;
	mouse_im = (double)y / (shape->img_y / (shape->y2 - shape->y1)) + shape->y1;
	sprintf(reel, "x: %f", mouse_re);
	mlx_string_put(shape->mlx, shape->win, 10, 530, RED, reel);
	sprintf(imag, "y: %f", mouse_im);
	mlx_string_put(shape->mlx, shape->win, 10, 550, RED, imag);
}

int			ft_var_julia(int x, int y, t_shape *ptr)
{
	if (ptr->ok == 1)
	{
		ptr->c_r = (double)x / (ptr->img_x / (ptr->x2 - ptr->x1)) + ptr->x1;
		ptr->c_i = (double)y / (ptr->img_y / (ptr->y2 - ptr->y1)) + ptr->y1;
	}
	ft_display(ptr);
	if (x >= 5 && x <= 125 && y >= 10 && y <= 35)
		ptr->string.mand = 0;
	else
		ptr->string.mand = RED;
	if (x >= 5 && x <= 125 && y >= 50 && y <= 75)
		ptr->string.julia = 0;
	else
		ptr->string.julia = RED;
	if (x >= 5 && x <= 125 && y >= 90 && y <= 115)
		ptr->string.burn = 0;
	else
		ptr->string.burn = RED;
	ft_print_coord(x, y, ptr);
	ft_set_string(ptr);
	return (0);
}

static void	ft_change_fract(t_shape *shape, int x, int y)
{
	if (x >= 5 && x <= 125 && y >= 10 && y <= 35)
	{
		shape->fract_name = FRACT1;
		ft_reset_fract(shape);
	}
	if (x >= 5 && x <= 125 && y >= 50 && y <= 75)
	{
		shape->fract_name = FRACT2;
		ft_reset_fract(shape);
	}
	if (x >= 5 && x <= 125 && y >= 90 && y <= 115)
	{
		shape->fract_name = FRACT3;
		ft_reset_fract(shape);
	}
}

int			ft_mouse_funct(int mouse, int x, int y, t_shape *shape)
{
	if (mouse == 5)
	{
		shape->iter += 5.0;
		shape->zoom *= 1.2;
		shape->in_out = mouse;
		apply_zoom(shape, x, y, 1.2);
	}
	if (mouse == 4)
	{
		shape->iter -= 5.0;
		shape->zoom /= 1.5;
		shape->in_out = mouse;
		apply_zoom(shape, x, y, 1.5);
	}
	if (mouse == 1)
		ft_change_fract(shape, x, y);
	ft_display(shape);
	ft_print_coord(x, y, shape);
	ft_set_string(shape);
	return (0);
}