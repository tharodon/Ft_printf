/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/25 22:23:10 by tharodon          #+#    #+#             */
/*   Updated: 2021/04/27 21:36:02 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
void	ft_putnbr_fd(int n, t_ps *params)
{
	char	tmp;

	if (n < 0)
	{
		write (1, "-", 1);
		params->len++;
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, params);
	tmp = (n % 10) + '0';
	write (1, &tmp, 1);
	params->len++;
}
