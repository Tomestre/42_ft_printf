/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtome-ve <gtome-ve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:31:11 by gtome-ve          #+#    #+#             */
/*   Updated: 2025/02/09 22:23:52 by gtome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fillformat_pf(va_list lst, char c, int *count)
{
	if (!count)
		return (-1);
	if (c == 'c')
		ft_putchar_pf(va_arg(lst, int), count);
	else if (c == 's')
		ft_putstr_pf(va_arg(lst, char *), count);
	else if (c == 'p')
		ft_putptr_pf(va_arg(lst, unsigned long long), count);
	else if (c == 'd' || c == 'i')
		ft_putnbr_pf(va_arg(lst, int), INT_BASE, count);
	else if (c == 'u')
		ft_putnbr_pf(va_arg(lst, unsigned int), INT_BASE, count);
	else if (c == 'x')
		ft_putnbr_pf(va_arg(lst, unsigned int), HEX_LOW_BASE, count);
	else if (c == 'X')
		ft_putnbr_pf(va_arg(lst, unsigned int), HEX_UPP_BASE, count);
	else if (c == '%')
		ft_putchar_pf(c, count);
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	lst;
	int		count;
	int		i;

	count = 0;
	i = 0;
	
	if (!str)
		return (-1);
	va_start(lst, str);
	while (str[i] && count != -1)
	{
		if (str[i] != '%')
			ft_putchar_pf(str[i], &count);
		else
			ft_fillformat_pf(lst, str[++i], &count);
		i++;
	}
	va_end(lst);
	return (count);
}