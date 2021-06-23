/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharodon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 15:15:25 by tharodon          #+#    #+#             */
/*   Updated: 2021/04/27 15:10:22 by tharodon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	schet (int i, int temp, const char *str)
{
	while (str[i] <= '9' && str[i] >= '0')
	{
		temp = (temp * 10) + (str[i] - 48);
		i++;
	}
	return (temp);
}

int	ft_atoi (const char *str)
{
	int		i;
	int		temp;
	int		minus;

	temp = 0;
	i = 0;
	minus = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+')
	{
		if (str[i + 1] == '-')
			return (temp);
		i++;
	}
	if (str[i] == '-')
	{
		minus++;
		i++;
	}
	temp = schet(i, temp, str);
	if (minus == 1)
		temp = temp * -1;
	return (temp);
}
