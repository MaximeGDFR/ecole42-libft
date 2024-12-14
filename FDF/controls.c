/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:34:16 by mgodefro          #+#    #+#             */
/*   Updated: 2024/12/14 14:38:47 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	reset(t_env *env)
{
	env->cam->x_offset = 0;
	env->cam->y_offset = 0;
	if (env->cam->iso)
	{
		env->cam->x_angle = -0.615472907;
		env->cam->y_angle = -0.523599;
		env->cam->z_angle = 0.615472907;
	}
	env->cam->z_height = 1;
	env->cam->zoom = ft_min(WIDTH / env->map->width / 2,
			HEIGHT / env->map->height / 2);
}

void	handle_zoom(int keycode, t_env *env)
{
	if (keycode == MINUS_KEY || keycode == M_KEY)
		env->cam->z_height += 0.1;
	else if (keycode == PLUS_KEY || keycode == P_KEY)
		env->cam->z_height -= 0.1;
	if (env->cam->z_height < 0.1)
		env->cam->z_height = 0.1;
	else if (env->cam->z_height > 10)
		env->cam->z_height = 10;
}

void	handle_moves(int keycode, t_env *env)
{
	if (keycode == UP)
		env->cam->y_offset -= 10;
	else if (keycode == DOWN)
		env->cam->y_offset += 10;
	else if (keycode == LEFT)
		env->cam->x_offset -= 10;
	else if (keycode == RIGHT)
		env->cam->x_offset += 10;
}

int	keyboards_controls(int keycode, t_env *env)
{
	t_point	point;

	if (keycode == UP || keycode == DOWN
		|| keycode == LEFT || keycode == RIGHT)
		handle_moves(keycode, env);
	else if (keycode == PLUS_KEY || keycode == MINUS_KEY
		|| keycode == P_KEY || keycode == M_KEY)
		handle_zoom(keycode, env);
	else if (keycode == C_KEY)
	{
		env->map->color_mode++;
		apply_color_mode(&point, env);
	}
	else if (keycode == SPACE)
	{
		env->map->current_view++;
		change_projection(&point, env);
	}
	else if (keycode == ENTER)
		reset(env);
/*	else if (keycode == ESC)
		quit_program(env);*/
	return (0);
}

void	hook_controls(t_env *env)
{
	mlx_hook(env->win, 2, 0, keyboards_controls, env);
	mlx_hook(env->win, 3, 0, handle_mouse, env);
//	mlx_hook(env->win, 17, 0, quit_program, env);
}
