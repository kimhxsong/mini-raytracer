/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yookim <yookim@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 02:09:27 by yookim            #+#    #+#             */
/*   Updated: 2022/02/02 21:38:24 by yookim           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static const t_hit	g_hit[] = {
	{hit_sphere},
	{hit_plane},
	{hit_cylinder}
};

int	hit(t_obj *obj, t_ray *ray, t_hit_record *rec)
{
	int				hit_result;
	t_hit_record	temp_rec;

	temp_rec = *rec;
	hit_result = FALSE;
	while (obj)
	{
		if (g_hit[obj->type].fn(obj, ray, &temp_rec))
		{
			hit_result = TRUE;
			temp_rec.color = obj->color;
			temp_rec.tmax = temp_rec.t;
			*rec = temp_rec;
		}
		obj = obj->next;
	}
	return (hit_result);
}
