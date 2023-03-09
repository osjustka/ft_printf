/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:16:01 by marvin            #+#    #+#             */
/*   Updated: 2023/03/07 12:16:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h> //for working with variable argument lists
# include <stdio.h> //provides facilities for input and output operations in C
# include <stdlib.h>
# include <unistd.h>
# define HEX_UPPER_BASE "0123456789ABCDEF"
# define HEX_LOWER_BASE "0123456789abcdef"

int ft_printf(char const *format, ...);
void    ft_putchar_pf(char c, size_t *ch_printed);
void	ft_putstr_pf(char *str, size_t *ch_printed);
void	ft_putnbr_pf(int num, size_t *ch_printed);
void	ft_putuint_pf(unsigned int num, size_t *ch_printed);
void	ft_puthex_pf(unsigned int num, size_t *ch_printed, char *base);
void	ft_putptr_pf(void *ptr, size_t *ch_printed);
char    *ft_transition_pf(unsigned long long n, char *base);

#endif