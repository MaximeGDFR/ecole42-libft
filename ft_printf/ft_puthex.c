/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:12:34 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/13 15:45:44 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*reorder_addr(char *addr, int len)
{
	int		start;
	int		end;
	char	temp;

	start = 2;
	end = len - 1;
	while (start < end)
	{
		temp = addr[start];
		addr[start] = addr[end];
		addr[end] = temp;
		start++;
		end--;
	}
	return (addr);
}

int	write_addr(unsigned long addr, char *hex_digits, char *buffer)
{
	int	i;

	i = 2;
	if (addr == 0)
		buffer[i++] = '0';
	while (addr > 0)
	{
		buffer[i++] = hex_digits[addr % 16];
		addr /= 16;
	}
	buffer[i] = '\0';
	reorder_addr(buffer, i);
	return (i);
}

int	ft_puthex(void *ptr, int type, t_flags *flags)
{
	unsigned long	addr;
	char			*hex_digits;
	int				count;
	int				spaces;
	char			buffer[20];

	addr = (unsigned long)ptr;
	if (flags->is_upper == 1)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	count = write_addr(addr, hex_digits, buffer);
	spaces = flags->width - count;
	if (spaces > 0 && !flags->zero)
		count = put_padding(count, spaces, 0);
	count += write(1, "0x", 2);
	count += write(1, buffer, count - 2);
	if (spaces > 0 && flags->zero)
		count = put_padding(count, spaces, 1);
	return (count);
}
