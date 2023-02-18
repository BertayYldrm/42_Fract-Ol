/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_man_jul.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:46 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/23 21:20:01 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

int	iterate_mandelbrot(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < ITER)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + \
			fractol->c.re, 2.0 * z.re * z.im + fractol->c.im);
		iteration++;
	}
	return (iteration);
}

int	iterate_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4 && iteration < ITER)
	{
		z = init_complex(pow(z.re, 2.0) - pow(z.im, 2.0) + \
			fractol->k.re, 2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}

int	jtest(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putendl(JULIAMASS);
		ft_putendl(JULIAVAL);
		exit(0);
	}
	while (str[i])
	{
		if (!(str[i] >= '0' && str[i] <= '9') && (str[i] != '.'
				&& str[i] != '-'))
		{
			ft_putendl(JULIAMASS);
			ft_putendl(JULIAVAL);
			exit(0);
			return (0);
		}
		i++;
	}
	return (1);
}
