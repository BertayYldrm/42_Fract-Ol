/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:40 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/27 19:53:07 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

t_image	*init_image(void *mlx)
{
	t_image	*image;

	image = ft_memalloc(sizeof(t_image));
	if (!(image))
		terminate(ERR_IMAGE_INIT);
	image->image = mlx_new_image(mlx, WIDTH, HEIGHT);
	if (!(image->image))
		terminate(ERR_IMAGE_INIT);
	image->data_addr = mlx_get_data_addr(image->image, &(image->bits_per_pixel),
			&(image->size_line), &(image->endian));
	return (image);
}

t_complex	init_complex(double re, double im)
{
	t_complex	complex;

	complex.re = re;
	complex.im = im;
	return (complex);
}

void	set_defaults(t_fractol *fractol)
{
	fractol->max_iteration = ITER;
	fractol->min = init_complex(-2.0, -2.0);
	fractol->max = init_complex(2.0, 2.0);
}

int	ft_close(void)
{
	exit(0);
}
