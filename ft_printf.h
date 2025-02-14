/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtome-ve <gtome-ve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:31:59 by gtome-ve          #+#    #+#             */
/*   Updated: 2025/02/14 20:17:17 by gtome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
#include <stdint.h>

# define INT_BASE "0123456789"
# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"

// Função para calcular o comprimento de uma string
size_t	ft_strlen_pf(char *str);

// Função para imprimir um caractere e atualizar o contador
void	ft_putchar_pf(char c, int *count);

// Função unificada para imprimir números (com ou sem sinal)
void	ft_putdata_pf(long long nbr, char *base, int *count, int is_signed);

// Função unificada para imprimir strings e ponteiros
void	ft_putstr_or_ptr_pf(char *str, int *count, int is_ptr);

// Função auxiliar para imprimir strings (reutiliza ft_putstr_or_ptr_pf)
void	ft_putstr_pf(char *str, int *count);

// Função para processar os formatos da string de formato
int		ft_fillformat_pf(va_list lst, char c, int *count);

// Função principal ft_printf
int		ft_printf(char const *str, ...);

#endif