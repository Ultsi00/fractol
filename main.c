/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 09:18:16 by tturto            #+#    #+#             */
/*   Updated: 2022/09/27 17:05:55 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	selected_fractal(int argc, char **argv)
{
	unsigned short int	select;

	if (argc != 2 || (ft_strncmp(argv[1], "mandelbrot", 11) != 0
			&& ft_strncmp(argv[1], "julia", 6) != 0
			&& ft_strncmp(argv[1], "tricorn", 8) != 0))
	{
		ft_putstr("Usage: send one argument for the program. ");
		ft_putstr("Argument must be one of the following:\n");
		ft_putstr("mandelbrot\njulia\ntricorn\n");
		exit (0);
	}
	select = 0;
	if (ft_strncmp(argv[1], "mandelbrot", 11) == 0)
		select = 1;
	if (ft_strncmp(argv[1], "julia", 6) == 0)
		select = 2;
	if (ft_strncmp(argv[1], "tricorn", 8) == 0)
		select = 3;
	return (select);
}

static void	initiliaze_render(t_container data)
{
	data.real_factor = (data.real_max - data.real_min) / (WIDTH - 1);
	data.imag_factor = (data.imag_max - data.imag_min) / (HEIGHT - 1);
	if (data.select == 1)
		mandelbrot(data);
	if (data.select == 2)
		mlx_hook(data.win, 6, 0, mouse_events_julia, &data);
	if (data.select == 3)
		tricorn(data);
}

int	main(int argc, char **argv)
{
	t_container	data;

	data.select = selected_fractal(argc, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	initialize_min_max_iter(&data);
	initiliaze_render(data);
	mlx_mouse_hook(data.win, mouse_zoom, &data);
	mlx_key_hook(data.win, key_events, &data);
	mlx_loop(data.mlx);
	return (0);
}
