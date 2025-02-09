/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_funlibft_pf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtome-ve <gtome-ve@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 20:29:30 by gtome-ve          #+#    #+#             */
/*   Updated: 2025/02/09 22:44:54 by gtome-ve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_pf(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void	ft_putchar_pf(char c, int *count)
{
	if (!count)
		return ;
	if (*count != -1)
	{
		if (write (1, &c, 1) == -1)
			*count = -1;
		else
			(*count)++;
	}
}

void	ft_putnbr_pf(long long nbr, char *base, int *count)
{
	size_t base_len;
	
	if (nbr < 0)
	{
		ft_putchar_pf('-', count);
		nbr *= -1;
	}
	base_len = ft_strlen_pf(base);
	if (nbr < (int)base_len)
    	ft_putchar_pf(base[nbr], count);
	else
	{
		ft_putnbr_pf(nbr / base_len, base, count);
		ft_putnbr_pf(nbr % base_len, base, count);
	}
}

void	ft_putstr_pf(char *str, int *count)
{
	if (!count)
		return ;
	if (!str)
		str = "(nil)";
	while (*str)
{		
	ft_putchar_pf(*str, count);
		str++;
	}
}

void	ft_putptr_pf(unsigned long long nbr, int *count)
{
	if (nbr == 0)
		ft_putstr_pf("(nil)", count);
	else
	{
		if (nbr > ft_strlen_pf(HEX_LOW_BASE))
		{
			ft_putstr_pf("0x", count);
    		ft_putnbr_pf(nbr, HEX_LOW_BASE, count);
		}
		else
    		ft_putnbr_pf(nbr, HEX_LOW_BASE, count);
	}
}