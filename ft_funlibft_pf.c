/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funlibft_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtome-ve <gtome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:29:30 by gtome-ve          #+#    #+#             */
/*   Updated: 2025/02/14 20:30:13 by gtome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Função principal para calcular o comprimento de uma string
size_t ft_strlen_pf(char *str)
{
    int i = -1;
    while (str[++i])
        ;
    return (i);
}

// Função principal para imprimir um caractere e atualizar o contador
void ft_putchar_pf(char c, int *count)
{
    if (!count || *count == -1)
        return;
    if (write(1, &c, 1) == -1)
        *count = -1;
    else
        (*count)++;
}

// Função unificada para imprimir números (com ou sem sinal) e strings
void ft_putdata_pf(long long nbr, char *base, int *count, int is_signed)
{
    size_t base_len = ft_strlen_pf(base);

    // Trata números com sinal se `is_signed` for verdadeiro
    if (is_signed && nbr < 0)
    {
        ft_putchar_pf('-', count);
        nbr *= -1;
    }

    // Converte recursivamente o número para a base especificada
    if ((unsigned long long)nbr < base_len) // Cast explícito para unsigned
    {
        ft_putchar_pf(base[(unsigned long long)nbr], count); // Cast explícito para unsigned
    }
    else
    {
        ft_putdata_pf(nbr / base_len, base, count, is_signed);
        ft_putdata_pf(nbr % base_len, base, count, is_signed);
    }
}

// Função unificada para imprimir strings e ponteiros
void ft_putstr_or_ptr_pf(char *str, int *count, int is_ptr)
{
    if (!count)
        return;

    // Caso especial para ponteiros nulos ou strings nulas
    if (!str)
    {
        if (is_ptr)
            str = "(nil)"; // Para %p, imprime (nil)
        else
            str = "(null)"; // Para %s, imprime (null)
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