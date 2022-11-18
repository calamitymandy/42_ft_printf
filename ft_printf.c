/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:50:39 by amdemuyn          #+#    #+#             */
/*   Updated: 2022/11/18 19:31:39 by amdemuyn         ###   ########.fr       */
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
		ft_putchar_len(num % 10 + 48, len);
	}
}

void	ft_putunsign(unsigned int num, int *len)
{
	if (num >= 10)
	{
		ft_putunsign(num / 10, len);
		ft_putunsign(num % 10, len);
	}
	else
		ft_putchar_len(num + 48, len);
}

void	ft_putstr(char *str, int *len)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)", len);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putchar_len(str[i], len);
		i++;
	}
}

void	ft_puthexa(unsigned long long num, char *base, int *len)
{
	if (num >= 16)
	{
		ft_puthexa(num / 16, base, len);
		ft_puthexa(num % 16, base, len);
	}
	else
		ft_putchar_len(base[num], len);
}

void	ft_check_type(va_list args, const char str, int *len)
{
	if (str == 'c')
		ft_putchar_len(va_arg(args, int), len);
	else if (str == '%')
		ft_putchar_len('%', len);
	else if (str == 'd' || str == 'i')
		ft_putnbr_len(va_arg(args, int), len);
	else if (str == 'u')
		ft_putunsign(va_arg(args, unsigned int), len);
	else if (str == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (str == 'x')
		ft_puthexa(va_arg(args, unsigned int), "0123456789abcdef", len);
	else if (str == 'X')
		ft_puthexa(va_arg(args, unsigned int), "0123456789ABCDEFG", len);
	else if (str == 'p')
	{
		ft_putstr("0x", len);
		ft_puthexa(va_arg(args, unsigned long long), "0123456789abcdef", len);
	}
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

/*int	main()
{
	//char test[] = "va chier des bulles";
	int test = -1;	
	ft_printf("%p", test);
	printf("\n%p", test);
}*/

int main(void)
{
	int t;
	char c;

	c = 'a';
	t = 50;
	printf("%p\n", NULL);
}
