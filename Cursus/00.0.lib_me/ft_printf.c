/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:56:54 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/22 14:56:56 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_spec(const char flags, va_list ap)
{
	unsigned int	count;

	count = 0;
	if (flags == 'c')
		count += ft_print_c(va_arg(ap, int));
	else if (flags == 's')
		count = ft_print_str(va_arg(ap, char *));
	else if (flags == 'i' || flags == 'd')
		count = ft_print_int(va_arg(ap, int));
	else if (flags == 'u')
		count = ft_print_uint(va_arg(ap, unsigned int));
	else if (flags == 'x' || flags == 'X')
		count = ft_print_hex(va_arg(ap, unsigned int), flags);
	else if (flags == 'p')
		count = ft_print_ptr(va_arg(ap, void *));
	else if (flags == '%')
		count += ft_print_c('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list			ap;
	unsigned int	count;
	int				i;

	i = 0;
	count = 0;
	if (str[i] == '%' && str[i + 1] == '\0')
		return (-1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (ft_strchr("cspdiuxX%", str[i++]))
				count += ft_spec(str[i++], ap);
			else
				count += ft_print_c(str[i++]);
		}
		else
			count += ft_print_c(str[i++]);
	}
	va_end(ap);
	return (count);
}

/*int	main()
{
	//char mystr[] = "pippo ng jdfsgkjdskljfg klsdjhgk ";
	int ret_fake;
	int ret_orig;

	ret_orig = printf("%s%s%s%s%s%s%s%s%s%s", "ciao", "ciao", "ciao", "ciao");
	printf("\n");
	ret_fake = ft_printf("%s%s%s%s%s%s%s%s%s%s", "ciao", "ciao", "ciao", "ciao");

	//ft_printf(" %c %c %c \n", '0', 0, '1');
	//printf(" %c %c %c \n", '0', 0, '1');
	printf("\nret orig: %d\nret fake: %d\n", ret_orig, ret_fake);
	return (0);
}*/
