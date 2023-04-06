/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_zoom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tturto <tturto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 17:26:13 by tturto            #+#    #+#             */
/*   Updated: 2022/09/27 17:06:18 by tturto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Scroll down		4
	Scroll up		5
*/
int	mouse_zoom(int key, int x, int y, t_container *data)
{
	x = 0;
	y = 0;
	if (key == 4)
	{
		data->real_min = data->real_min * 0.95;
		data->real_max = data->real_max * 0.95;
		data->imag_min = data->imag_min * 0.95;
		data->imag_max = data->imag_max * 0.95;
	}
	if (key == 5)
	{
		data->real_min = data->real_min * 1.05;
		data->real_max = data->real_max * 1.05;
		data->imag_min = data->imag_min * 1.05;
		data->imag_max = data->imag_max * 1.05;
	}
	data->real_factor = (data->real_max - data->real_min) / (WIDTH - 1);
	data->imag_factor = (data->imag_max - data->imag_min) / (HEIGHT - 1);
	if (data->select == 1)
		mandelbrot(*data);
	if (data->select == 2)
		mlx_hook(data->win, 6, 0, mouse_events_julia, data);
	if (data->select == 3)
		tricorn(*data);
	return (0);
}
