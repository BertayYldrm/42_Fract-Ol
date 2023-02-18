/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: beyildir <beyildir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 21:04:33 by beyildir          #+#    #+#             */
/*   Updated: 2023/01/23 21:19:22 by beyildir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# define ITER 90

# define WIDTH 1000
# define HEIGHT 1000

# include "../mlxlib/mlx.h"
# include "libft.h"
# include <math.h>

typedef struct s_color
{
	int			channel[4];
}				t_color;

typedef struct s_complex
{
	double		re;
	double		im;
}				t_complex;

typedef struct s_image
{
	void		*image;
	char		*data_addr;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
}				t_image;

typedef struct s_fractol
{
	void		*mlx;
	void		*window;
	t_image		*image;
	int			max_iteration;
	t_complex	min;
	t_complex	max;
	t_complex	factor;
	t_complex	c;
	t_complex	k;
	char		check;
}				t_fractol;

t_image			*init_image(void *mlx);
t_complex		init_complex(double re, double im);
void			set_defaults(t_fractol *fractol);
void			draw_fractal(t_fractol *fractol);
void			draw_help(t_fractol *fractol);
int				iterate_mandelbrot(t_fractol *fractol);
int				iterate_burningship(t_fractol *fractol);
int				iterate_julia(t_fractol *fractol);
t_color			get_color(t_fractol *fractol);
int				key_press(int key);
int				zoom(int button, int x, int y, t_fractol *fractol);
int				ft_atoi(char *str);
double			ft_atod(char *str);
int				ft_close(void);
int				jtest(char *str);
void			print_help(void);
void			terminate(char *s);

# define ERROR_MESSAGE_H

# define ERR_FRACTOL_INIT "ERROR: Can\'t initialize fractol"
# define ERR_WINDOW_INIT "ERROR: Can\'t initialize window"
# define ERR_IMAGE_INIT "ERROR: Can\'t initialize image"

# define ERR_FRACTAL_NAME "ERROR: No such fractal"

// KEYS

# define MOUSE_SCROLL_UP 4
# define MOUSE_SCROLL_DOWN 5

# define KEYPRESS 2
# define BUTTONPRESS 4

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define MAIN_PAD_ESC 53
# define MAIN_PAD_SPACE 49
# define MAIN_PAD_C 8
# define X_BUTTON 17

//Julia Values

# define JULIAMASS "Please enter a valid Julia value"
# define JULIAVAL "-0.4 , 0.6  ||  0.285 , 0.01  ||  -0.8 , 0.156"

#endif
