/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 21:27:30 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/02/02 13:14:49 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ctype.h"

int	ft_isspace(int c)
{
	return (((unsigned char)c >= 0x9 && (unsigned char)c <= 0xd)
		|| (unsigned char)c == 0x20);
}
