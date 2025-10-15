/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmath.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 11:52:54 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/15 15:35:36 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATH_H
# define LIBFTMATH_H

#include <stdio.h>
#include <math.h>

/* Structures */
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
t_vec3	ft_vec3(const float x, const float y, const float z);
t_vec4	ft_vec4(const float x, const float y, const float z, const float w);
t_mat4	ft_mat4(void);

void	ft_print_vec3(const t_vec3 v, const char *name);
void	ft_print_vec4(const t_vec4 v, const char *name);
void	ft_print_mat4(const t_mat4 m, const char *name);

t_vec3	ft_vec3_add(t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_sadd(t_vec3 v1, const float n);
t_vec4	ft_vec4_add(t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_sadd(t_vec4 v1, const float n);
t_vec3	ft_vec3_sub(t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_ssub(t_vec3 v1, const float n);
t_vec4	ft_vec4_sub(t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_ssub(t_vec4 v1, const float n);
t_vec3	ft_vec3_mul(t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_smul(t_vec3 v1, const float n);
t_vec4	ft_vec4_mul(t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_smul(t_vec4 v1, const float n);
t_vec4	ft_vec4_mmul(const t_vec4 v, const t_mat4 m);
t_vec3	ft_vec3_div(t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_sdiv(t_vec3 v1, const float n);
t_vec4	ft_vec4_div(t_vec4 v1, const t_vec4 v2);
t_vec4	ft_vec4_sdiv(t_vec4 v1, const float n);

float	ft_vec3_len(const t_vec3 v);
float	ft_vec4_len(const t_vec4 v);
t_vec3	ft_vec3_normalize(const t_vec3 v);
t_vec4	ft_vec4_normalize(const t_vec4 v);
float	ft_vec3_dot(const t_vec3 v1, const t_vec3 v2);
float	ft_vec4_dot(const t_vec3 v1, const t_vec3 v2);
t_vec3	ft_vec3_cross(const t_vec3 v1, const t_vec3 v2);

t_mat4	ft_mat4_add(t_mat4 m1, const t_mat4 m2);
t_mat4	ft_mat4_sadd(t_mat4 m1, const float n);
t_mat4	ft_mat4_sub(t_mat4 m1, const t_mat4 m2);
t_mat4	ft_mat4_ssub(t_mat4 m1, const float n);
t_mat4	ft_mat4_mul(const t_mat4 m1, const t_mat4 m2);
t_vec4	ft_mat4_vec4_mul(const t_mat4 m, const t_vec4 v);
t_vec4	ft_mat4_vec4_mul(const t_mat4 m, const t_vec4 v);

t_mat4	ft_mat4_trans(const t_vec4 trans);

#endif