/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:03:42 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/27 22:22:05 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers_bonus/fractol_bonus.h"

int	get_formula(char **name, t_fractol *fractol)
{
	if (ft_strequ(name[1], "Julia") && jtest(name[2]) && jtest(name[3]))
	{
		fractol->check = 'j';
		fractol->k.re = ft_atod(name[2]);
		fractol->k.im = ft_atod(name[3]);
		return (1);
	}
	else if (ft_strequ(name[1], "Mandelbrot"))
	{
		fractol->check = 'm';
		return (1);
	}
	else if (ft_strequ(name[1], "Burningship"))
	{
		fractol->check = 'b';
		return (1);
	}
	else
		print_help();
	return (0);
}

t_fractol	*init_fractol(char **name, void *mlx)
{
	t_fractol	*fractol;

	fractol = ft_memalloc(sizeof(t_fractol));
	if (!(fractol))
		terminate(ERR_FRACTOL_INIT);
	fractol->mlx = mlx;
	fractol->window = mlx_new_window(mlx, WIDTH, HEIGHT, name[1]);
	if (!(fractol->window))
		terminate(ERR_WINDOW_INIT);
	fractol->image = init_image(mlx);
	set_defaults(fractol);
	if (!(get_formula(name, fractol)))
		terminate(ERR_FRACTAL_NAME);
	mlx_hook(fractol->window, KEYPRESS, 0, key_press, fractol);
	mlx_hook(fractol->window, X_BUTTON, 0, ft_close, fractol);
	mlx_hook(fractol->window, BUTTONPRESS, 0, zoom, fractol);
	return (fractol);
}

void	start(char **names)
{
	t_fractol	*fractols;
	void		*mlx;

	mlx = mlx_init();
	fractols = init_fractol(names, mlx);
	draw_fractal(fractols);
	mlx_loop(mlx);
}

int	main(int ac, char **ag)
{
	if (ac == 2 || ac == 4)
		start(ag);
	print_help();
	return (0);
}
