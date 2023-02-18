/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_m_k.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:54 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/27 19:48:14 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

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

int	key_press(int key)
{
	if (key == MAIN_PAD_ESC)
		exit(0);
	return (0);
}
