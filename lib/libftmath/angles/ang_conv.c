/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ang_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbelomet <sbelomet@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:16:23 by sbelomet          #+#    #+#             */
/*   Updated: 2025/10/16 14:17:55 by sbelomet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmath.h"

double	ft_deg_to_rad(double deg)
{
	return (deg * M_PI / 180);
}

double	ft_rad_to_deg(double rad)
{
	return (rad * 180 / M_PI);
}