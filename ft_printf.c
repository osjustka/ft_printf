/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 12:16:17 by marvin            #+#    #+#             */
/*   Updated: 2023/03/07 12:16:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_format(va_list args, char *format, size_t *ch_printed)
{
    if (*format == 'c') //Prints a single character
        ft_putchar_pf(va_arg(args, int), ch_printed);
    else if (*format == 's') //Prints string
        ft_putstr_pf(va_arg(args, char *), ch_printed);
    else if (*format == 'p') //The void * pointer argument has to be printed in hexadecimal format.
        ft_putptr_pf(va_arg(args, void *), ch_printed);
    else if (*format == 'd' || *format == 'i')// Prints integer or Prints integers in either decimal, octal, or hexadecimal format.
        ft_putnbr_pf(va_arg(args, int), ch_printed);
    else if (*format == 'u')//Prints an unsigned decimal (base 10) number
        ft_putuint_pf(va_arg(args, unsigned int), ch_printed);
    else if (*format == 'x' || *format == 'X')//Prints a number in hexadecimal (base 16) lowercase or uppercase format
        {
            if (*format == 'x')
                ft_puthex_pf(va_arg(args, unsigned int), ch_printed, HEX_LOWER_BASE);
            else
                ft_puthex_pf(va_arg(args, unsigned int), ch_printed, HEX_UPPER_BASE);
        } 
    else if (*format == '%')
        ft_putchar_pf(*format, ch_printed);
}

int ft_printf(const char *format, ...)
{
    va_list args;
    size_t ch_printed;
    
    if (*format == '\0')
        return(0);
    ch_printed = 0;
    va_start(args, format);
    while (*format != '\0')
    {
        if ( *format == '%')
        {
            format++;
            ft_format(args, (char *)format, &ch_printed);
        }
        else 
            ft_putchar_pf(*format, &ch_printed);
        format++;
    }
    va_end(args);
    return (ch_printed); // returns the numbe of characters printed (excluding the null byte)
}
