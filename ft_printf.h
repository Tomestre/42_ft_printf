/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtome-ve <gtome-ve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:31:59 by gtome-ve          #+#    #+#             */
/*   Updated: 2025/02/16 15:44:25 by gtome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define INT_BASE "0123456789"
# define HEX_UPP_BASE "0123456789ABCDEF"
# define HEX_LOW_BASE "0123456789abcdef"


size_t	ft_strlen_pf(char *str);


void	ft_putchar_pf(char c, int *count);


void	ft_putdata_pf(long long nbr, char *base, int *count, int is_signed);


void	ft_putstr_or_ptr_pf(char *str, int *count, int is_ptr);


void	ft_putstr_pf(char *str, int *count);


int		ft_fillformat_pf(va_list lst, char c, int *count);


int		ft_printf(char const *str, ...);

#endif
