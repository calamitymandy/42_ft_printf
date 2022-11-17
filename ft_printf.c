/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:50:39 by amdemuyn          #+#    #+#             */
/*   Updated: 2022/11/17 19:03:09 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_putchar_len(char c, int *len)
{
	write(1, &c, 1);
	*len = *len +1;
}

void	ft_putnbr_len(int num, int *len)
{
	if (num == -2147483648)
	{
		write (1, "-2147483648", 11);
		(*len) += 11;
		return ;
	}
	if (num < 0)
	{
		ft_putchar_len('-', len);
		ft_putnbr_len(num * -1, len);
	}
	else
	{
		if (num > 9)
			ft_putnbr_len(num / 10, len);
		ft_putchar_len(num % 10 + '0', len);
	}
}

void	ft_check_type(va_list args, const char str, int *len)
{
	if (str == 'c')
		ft_putchar_len(va_arg(args, int), len);
	else if (str == '%')
		ft_putchar_len('%', len);
	else if (str == 'd' || str == 'i')
		ft_putnbr_len(va_arg(args, int), len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_check_type(args, str[i + 1], &len);
			i++;
		}
		else
		{
			ft_putchar_len((char)str[i], &len);
		}
		i++;
	}
	va_end(args);
	return (len);
}

int	main()
{
	int test = -2147483648;
	ft_printf("%d", test);
	printf("\n%d", test);
}
