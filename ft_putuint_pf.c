/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint_pf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 10:49:04 by marvin            #+#    #+#             */
/*   Updated: 2023/03/08 10:49:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_putuint_pf(unsigned int n, size_t *ch_printed)
{
    char *str;

    str = ft_transition_pf(n, "0123456789");
    ft_putstr_pf(str, ch_printed);
    free(str);
}