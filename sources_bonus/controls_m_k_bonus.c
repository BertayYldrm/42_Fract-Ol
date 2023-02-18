/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_m_k_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:54 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/28 00:42:26 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/fractol_bonus.h"

int	zoom(int button, int x, int y, t_fractol *fractol)
{
	double	zoom;

	(void)x;
	(void)y;
	if (button == MOUSE_SCROLL_UP || button == MOUSE_SCROLL_DOWN)
	{
		if (button == MOUSE_SCROLL_UP)
			zoom = 0.80;
		else
			zoom = 1.20;
		fractol->min.re = (fractol->min.re * zoom);
		fractol->min.im = (fractol->min.im * zoom);
		fractol->max.re = (fractol->max.re * zoom);
		fractol->max.im = (fractol->max.im * zoom);
		draw_fractal(fractol);
	}
	return (0);
}

static void	change_color_shift(t_fractol *fractol)
{
	fractol->color_shift = (fractol->color_shift + 1) % 3;
	draw_fractal(fractol);
}

int	key_press(int key, t_fractol *fractol)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	else if (key == MAIN_PAD_C)
		change_color_shift(fractol);
	return (0);
}
