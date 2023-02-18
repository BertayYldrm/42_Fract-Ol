/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:51 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/27 23:17:33 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/fractol_bonus.h"

static void	put_pixel(t_fractol *fractol, int x, int y, t_color color)
{
	int	i;

	i = (x * fractol->image->bits_per_pixel / 8) + (y
			* fractol->image->size_line);
	fractol->image->data_addr[i] = color.channel[3];
	fractol->image->data_addr[++i] = color.channel[2];
	fractol->image->data_addr[++i] = color.channel[1];
	fractol->image->data_addr[++i] = color.channel[0];
}

static void	draw_fractal_part(t_fractol *fractol)
{
	int		y;
	int		x;
	t_color	color;

	y = -1;
	while (++y < HEIGHT)
	{
		fractol->c.im = fractol->max.im - y * fractol->factor.im;
		x = -1;
		while (++x < WIDTH)
		{
			fractol->c.re = fractol->min.re + x * fractol->factor.re;
			color = get_color(fractol);
			put_pixel(fractol, x, y, color);
		}
	}
}

void	draw_fractal(t_fractol *fractol)
{
	fractol->factor = init_complex((fractol->max.re - fractol->min.re)
			/ (WIDTH), (fractol->max.im - fractol->min.im) / (HEIGHT));
	draw_fractal_part(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->window, \
		fractol->image->image, 0, 0);
	mlx_string_put(fractol->mlx, fractol->window, \
	(HEIGHT - 100), (WIDTH - 35), WHITE, "Bertay");
}
