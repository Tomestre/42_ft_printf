/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtome-ve <gtome-ve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:31:11 by gtome-ve          #+#    #+#             */
/*   Updated: 2025/02/14 22:34:42 by gtome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_fillformat_pf(va_list lst, char c, int *count)
{
    if (!count)
        return (-1);

    if (c == 'c') // Caractere
    {
        ft_putchar_pf((char)va_arg(lst, int), count);
    }
    else if (c == 's') // String
    {
        ft_putstr_or_ptr_pf(va_arg(lst, char *), count, 0); // Usa is_ptr = 0 para strings
    }
    else if (c == 'p') // Ponteiro
    {
        ft_putstr_or_ptr_pf(va_arg(lst, void *), count, 1); // Usa is_ptr = 1 para ponteiros
    }
    else if (c == 'd' || c == 'i') // Inteiro com sinal
    {
        ft_putdata_pf((long long)va_arg(lst, int), INT_BASE, count, 1);
    }
    else if (c == 'u') // Inteiro sem sinal
    {
        ft_putdata_pf((unsigned long long)va_arg(lst, unsigned int), INT_BASE, count, 0);
    }
    else if (c == 'x') // Hexadecimal minúsculo
    {
        ft_putdata_pf((unsigned long long)va_arg(lst, unsigned int), HEX_LOW_BASE, count, 0);
    }
    else if (c == 'X') // Hexadecimal maiúsculo
    {
        ft_putdata_pf((unsigned long long)va_arg(lst, unsigned int), HEX_UPP_BASE, count, 0);
    }
    else if (c == '%') // Porcentagem
    {
        ft_putchar_pf('%', count);
    }

    return (0);
}

int ft_printf(char const *str, ...)
{
    va_list lst;
    int     count;
    int     i;

    count = 0;
    i = 0;
    if (!str)
        return (-1);

    va_start(lst, str);
    while (str[i] && count != -1)
    {
        if (str[i] != '%')
        {
            ft_putchar_pf(str[i], &count);
        }
        else
        {
            i++;
            ft_fillformat_pf(lst, str[i], &count);
        }
        i++;
    }
    va_end(lst);

    return (count);
}