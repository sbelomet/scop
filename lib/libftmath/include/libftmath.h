/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmath.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:52:54 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/28 12:23:18 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATH_H
# define LIBFTMATH_H

# include <stdio.h>
# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846264338327950288
# endif

/* Structures */
typedef struct	s_vec2
{
	float	v[2];
}				t_vec2;

typedef struct	s_vec3
{
	float	v[3];
}				t_vec3;

typedef struct	s_vec4
{
	float	v[4];
}				t_vec4;

typedef struct	s_mat4
{
	float	m[16];
}				t_mat4;

/* Functions */

double	ft_deg_to_rad(double deg);
double	ft_rad_to_deg(double rad);

t_vec2	ft_vec2(const float x, const float y);
t_vec3	ft_vec3(const float x, const float y, const float z);
t_vec3	ft_vec3_null(void);
t_vec4	ft_vec4(const float x, const float y, const float z, const float w);
t_vec4	ft_vec4_null(void);
t_mat4	ft_mat4(void);
t_mat4	ft_mat4_null(void);

void	ft_print_vec3(const t_vec3 v, const char *name);
void	ft_print_vec4(const t_vec4 v, const char *name);
void	ft_print_mat4(const t_mat4 m, const char *name);

t_vec3	ft_vec3_add(const t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_sadd(const t_vec3 v1, const float n);
t_vec4	ft_vec4_add(const t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_sadd(const t_vec4 v1, const float n);
t_vec3	ft_vec3_sub(const t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_ssub(const t_vec3 v1, const float n);
t_vec4	ft_vec4_sub(const t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_ssub(const t_vec4 v1, const float n);
t_vec3	ft_vec3_mul(const t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_smul(const t_vec3 v1, const float n);
t_vec4	ft_vec4_mul(const t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_smul(const t_vec4 v1, const float n);
t_vec4	ft_vec4_mmul(const t_vec4 v, const t_mat4 m);
t_vec3	ft_vec3_div(const t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_sdiv(const t_vec3 v1, const float n);
t_vec4	ft_vec4_div(const t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_sdiv(const t_vec4 v1, const float n);

float	ft_vec3_len(const t_vec3 v);
float	ft_vec4_len(const t_vec4 v);
t_vec3	ft_vec3_normalize(const t_vec3 v);
t_vec4	ft_vec4_normalize(const t_vec4 v);
float	ft_vec3_dot(const t_vec3 v1, const t_vec3 v2);
float	ft_vec4_dot(const t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_cross(const t_vec3 v1, const t_vec3 v2);

t_mat4	ft_mat4_add(const t_mat4 m1, const t_mat4 m2);
t_mat4	ft_mat4_sadd(const t_mat4 m1, const float n);
t_mat4	ft_mat4_sub(const t_mat4 m1, const t_mat4 m2);
t_mat4	ft_mat4_ssub(const t_mat4 m1, const float n);
t_mat4	ft_mat4_mul(const t_mat4 m1, const t_mat4 m2);
t_vec4	ft_mat4_vec4_mul(const t_mat4 m, const t_vec4 v);
t_vec4	ft_mat4_vec4_mul(const t_mat4 m, const t_vec4 v);

t_mat4	ft_mat4_transl(const t_vec3 transl);
t_mat4	ft_mat4_scale(const t_vec3 scale);
t_mat4	ft_mat4_rot(t_vec3 rot_axis, const float angle);

t_mat4	ft_mat4_persp(const float fov, const float asp_ratio, const float near, const float far);

#endif