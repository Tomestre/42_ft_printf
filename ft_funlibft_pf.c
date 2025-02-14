/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funlibft_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtome-ve <gtome-ve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:29:30 by gtome-ve          #+#    #+#             */
/*   Updated: 2025/02/14 22:31:09 by gtome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t ft_strlen_pf(char *str)
{
    int i = -1;
    while (str[++i])
        ;
    return (i);
}

void ft_putchar_pf(char c, int *count)
{
    if (!count || *count == -1)
        return;
    if (write(1, &c, 1) == -1)
        *count = -1;
    else
        (*count)++;
}

void ft_putdata_pf(long long nbr, char *base, int *count, int is_signed)
{
    size_t base_len;

    if (is_signed && nbr < 0)
    {
        ft_putchar_pf('-', count);
        nbr *= -1;
    }

    base_len = ft_strlen_pf(base);

    if ((unsigned long long)nbr < base_len)
    {
        ft_putchar_pf(base[(unsigned long long)nbr], count); 
    }
    else
    {
        ft_putdata_pf(nbr / base_len, base, count, is_signed);
        ft_putdata_pf(nbr % base_len, base, count, is_signed);
    }
}


void ft_putstr_or_ptr_pf(char *str, int *count, int is_ptr)
{
    if (!count)
        return;
    if (!str)
    {
        if (is_ptr)
            str = "(nil)";
        else
            str = "(null)";
    }
    else if (is_ptr) // Para ponteiros, adiciona o prefixo "0x"
    {
        ft_putstr_pf("0x", count);
        ft_putdata_pf((unsigned long long)(uintptr_t)str, HEX_LOW_BASE, count, 0); // Trata como unsigned long long
        return;
    }

    // Imprime cada caractere da string
    while (*str)
    {
        ft_putchar_pf(*str, count);
        str++;
    }
}

// Função auxiliar para imprimir strings (reutilizada em ft_putstr_or_ptr_pf)
void ft_putstr_pf(char *str, int *count)
{
    ft_putstr_or_ptr_pf(str, count, 0); // Chama ft_putstr_or_ptr_pf com is_ptr = 0
}