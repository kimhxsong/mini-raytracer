/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeonsok <hyeonsok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 19:21:14 by hyeonsok          #+#    #+#             */
/*   Updated: 2022/01/17 19:11:12 by hyeonsok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "parse.h"

int ft_isfloatform(char *str)
{
    char    *tmp;
    int     i;

    str += ft_issign(*str);
    while(isdigit(*str))
        ++str;
    str += *str == '.';
    while (isdigit(*str))
        ++str;
    if (!*str)
        return (1);
    return (0);
}

int ft_isvecform(char *str)
{
    char    *token;
    int     count;
    
    count = 3;
    token = strtok(str, ",");
    while (count > 0 && token)
    {
        if (!ft_isfloatform(token))
            break ;
        --count;
        token = strtok(NULL, ",");
    }
    if (!count && !token)
        return (1);
    return (0);
}

static int ft_isintform(char *str)
{
    int     maxlen;

    maxlen = 10;
    str += ft_issign(*str);
    while(isdigit(*str) && maxlen-- > 0)
        ++str;
    if (!*str)
        return (1);
    return (0);
}

int ft_isrgbform(char *str)
{
    char    *token;
    int     count;

    count = 3;
    token = strtok(str, ",");
    while (count > 0 && token)
    {
        if (!ft_isintform(token))
            break ;
        --count;
        token = strtok(NULL, ",");
    }
    if (!count && !token)
        return (1);
    return (0);
}
