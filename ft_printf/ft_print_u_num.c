/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maximegdfr <maximegdfr@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:57:47 by maximegdfr        #+#    #+#             */
/*   Updated: 2024/11/16 22:25:57 by maximegdfr       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_u_num(unsigned long nl)
{
	int				count;
	unsigned long	num;

	count = 0;
	num = nl;
	if (num > 100)
		count += print_u_num(num / 10);
	else if (num == 100)
		count += print_str("10");
	else if ((num / 10) > 0)
		count += print_char((num / 10) + '0');
	count += print_char(num % 10 + '0');
	return (count);
}

static int	num_lenght(unsigned long num)
{
	int	cur;

	cur = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 10;
		cur++;
	}
	return (cur);
}

static int	get_values(char *pre, int *lp, t_flags *flags, unsigned long num)
{
	int		len;

	len = num_lenght(num);
	*lp = len;
	if (flags->precision > len)
		*lp = flags->precision;
	*pre = '0';
	if (flags->zero && flags->dot && flags->zero_offset > flags->precision)
		*pre = ' ';
	if (!flags->zero)
		*pre = ' ';
	if (flags->zero)
		flags->min_width = flags->zero_offset;
	if (flags->precision > flags->min_width)
		flags->min_width = flags->precision;
	return (len);
}

static int	print_u(int len, unsigned long num, t_flags *flags)
{
	int		count;

	count = 0;
	if (num == 0 && flags->min_width && flags->min_width < len)
		count += print_char(' ');
	else if (num == 0 && flags->dot && !flags->precision
		&& flags->min_width >= len)
		count += print_char(' ');
	else if (!(num == 0 && flags->dot && !flags->precision))
		count += print_number(num);
	return (count);
}

int	ft_print_u_num(unsigned long num, t_flags *flags)
{
	int		count;
	int		len;
	int		len_prec;
	char	prefix;

	count = 0;
	len = get_values(&prefix, &len_prec, flags, num);
	while (len_prec + count < flags->min_width)
		count += print_char(prefix);
	while (len + count < flags->min_width)
		count += print_char('0');
	count += print_u(len, num, flags);
	while (count < flags->offset)
		count += print_char(' ');
	return (count);
}