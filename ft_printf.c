/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amdemuyn <amdemuyn@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 16:50:39 by amdemuyn          #+#    #+#             */
/*   Updated: 2022/11/15 17:44:46 by amdemuyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int	i;
	int	len;

	i = 0;
	len = 0;
	va_start	(args, str);
	while (str[i] != '\0')
	{
		if (!str)
			return (NULL);
		if (str[i] == '%')
		{
			ft_check_arg(str[i], &args, &len, &i); 
		}
		else
		{
			ft_putchar_len((char)str[i], &len);
		}
	}
	va_end(args);
	return (len);
}
