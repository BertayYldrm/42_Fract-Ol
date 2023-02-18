/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:30 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/27 19:14:32 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/fractol.h"

void	terminate(char *s)
{
	ft_putendl(s);
	exit(0);
}

t_color	get_color(t_fractol *fractol)
{
	t_color	color;
	double	iteration;
	double	t;

	iteration = 0;
	if (fractol->check == 'm')
		iteration = iterate_mandelbrot(fractol);
	else if (fractol->check == 'j')
		iteration = iterate_julia(fractol);
	t = iteration / ITER;
	color.channel[0] = 0;
	color.channel[1] = 5 * t * t * 255;
	color.channel[2] = 2 * t * t * 255;
	color.channel[3] = 4 * t * t * 255;
	return (color);
}

void	print_help(void)
{
	ft_putendl("Usage: ./fractol <name>");
	ft_putendl("\n");
	ft_putendl("List of available fractals:");
	ft_putendl(" * Mandelbrot");
	ft_putendl(" * Julia");
}

void	*ft_memalloc(size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!(ptr))
		ft_bzero(ptr, size);
	return (ptr);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
		*ptr++ = '\0';
}
