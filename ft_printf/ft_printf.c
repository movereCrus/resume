/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwarlock <dwarlock@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:13:29 by dwarlock          #+#    #+#             */
/*   Updated: 2022/01/03 18:37:35 by dwarlock         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	sphandler(char sp, va_list *ap, int fwe)
{
	if (sp == 'c')
		return (write(1, &fwe, 1));
	else if (sp == 'd' || sp == 'i')
		return (putnbr_d(fwe, "0123456789"));
	else if (sp == 'u')
		return (putnbr_uhex(fwe, "0123456789", 10));
	else if (sp == 'x')
		return (putnbr_uhex(fwe, "0123456789abcdef", 16));
	else if (sp == 'X')
		return (putnbr_uhex(fwe, "0123456789ABCDEF", 16));
	else if (sp == 'p')
	{
		write(1, "0x", 2);
		return (putnbr_p(va_arg(*ap, size_t), "0123456789abcdef") + 2);
	}
	else if (sp == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

static int	ft_primaryloop(char *str, int i, int wrbytes, va_list *ap)
{
	int		fwe;

	fwe = 0;
	while (str[i] != 0)
	{
		if (str[i] == '%' && checkfmt("cpsdiuxX%", str[i + 1]))
		{
			if (checkfmt("dic", str[i + 1]))
				fwe = va_arg(*ap, int);
			else if (checkfmt("uxX", str[i + 1]))
				fwe = va_arg(*ap, unsigned int);
			else if (checkfmt("s", str[i + 1]))
				wrbytes += ft_putstr(va_arg(*ap, char *));
			wrbytes += sphandler(str[i + 1], ap, fwe);
			i += 2;
		}
		else
			wrbytes += write(1, &str[i++], 1);
	}
	va_end(*ap);
	return (wrbytes);
}

int	ft_printf(const char *fmt, ...)
{
	char	*str;
	int		i;
	int		wrbytes;
	va_list	ap;

	i = 0;
	wrbytes = 0;
	str = (char *)fmt;
	va_start(ap, fmt);
	return (ft_primaryloop(str, i, wrbytes, &ap));
}
