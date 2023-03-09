/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:30:22 by marvin            #+#    #+#             */
/*   Updated: 2023/03/02 12:30:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h> //for working with variable argument lists
#include <stdio.h> //provides facilities for input and output operations in C
#include <stdlib.h>
#include <unistd.h>
#include <libft.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    size_t *ch_printed;
    char c;
    char *s;
    void *ptr;
    int num;
    unsigned int numbr;
    
    ch_printed = 0;
    va_start(args, format);
    while (*format != '\0')
    {
        if ( *format == %)
        {
            format++;
            if (*format == 'c') { //single character
                c = va_arg(args, int);
                ft_putchar_pf(c, ch_printed);
            }
            else if (*format == 's') { // string
                s = va_arg(args, char *);
                fputs(s, stdout);  // change to a function that puts a string
            }
            else if (*format == 'p') {  /* The void * pointer argument has to be printed in hexadecimal format. */
                ptr = va_arg(args, void *);
                printf("%p", ptr); // change to a function that prints the hexadecimal format
            }
            else if (*format == 'd' || *format == 'i') { // prints decimal or integer
                num = va_arg(args, int);
                printf("%p", ptr); // change to a function that prints numbers
            } 
            else if (*format == 'u') { //Prints an unsigned decimal (base 10) number
                numbr = va_arg(args, unsigned int);
                printf("%u", num);  // change to a function that prints numbers
            }
            else if (*format == 'x') { //Prints a number in hexadecimal (base 16) lowercase format
                numbr = va_arg(args, unsigned int);
                printf("%x", num);// change to a function that prints numbers
            } 
            else if (*format == 'X') {//Prints a number in hexadecimal (base 16) uppercase format
                numbr = va_arg(args, unsigned int);
                printf("%X", num); // change to a function that prints numbers
            }
            else if (*format == '%')
                ft_putchar_pf('%', ch_printed);
        }
        else 
            ft_putchar_pf(*format, ch_printed);
        format++;
    }
    va_end(args);
    return ch_printed; // returns the numbe of characters printed (excluding the null byte)
}

void	ft_putchar_pf(char c, size_t *counter)
{
	write(1, &c, 1);
	(*ch_printed)++; // increasing the pointer with each character printed
}

int main(){

    return 0;
}
