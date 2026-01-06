/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qcorsius <qcorsius@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 12:48:02 by qcorsius          #+#    #+#             */
/*   Updated: 2025/12/12 12:18:46 by qcorsius         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_putchar(char c, int *total);
int	put_integer(long number, int *total);
int	ft_putstr(char *str, int *total);
int	put_nb_base(unsigned long number, char *base, int *total);

int	ft_printf(const char *str, ...);

#endif