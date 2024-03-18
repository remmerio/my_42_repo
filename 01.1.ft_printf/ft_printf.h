/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbellard <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 17:07:17 by mbellard          #+#    #+#             */
/*   Updated: 2024/01/19 17:07:22 by mbellard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h> // variable argument lists
# include "./libft/libft.h" // my library

/* --- BASIC FUNCTIONS --- */
int	ft_printf(const char *str, ...);

/* --- SPECIFIERS FUNCTION --- */
// c
int	ft_print_c(int c);
// s
int	ft_print_str(char *str);
// i, d
int	ft_print_int(int n);
// u
int	ft_print_uint(unsigned int nb);
// x, X
int	ft_print_hex(unsigned int nb, const char flags);
// p
int	ft_print_ptr(void *ptr);
#endif
