#include "ft_printf.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
void	ft_hexal_low(unsigned long long n, t_ps *params)
{
	int		temp_ost;
	char	dst[17] = "0123456789abcdef";

	if (n >= 16)
		ft_hexal_low(n / 16, params);
	temp_ost = n % 16;
	write (1, &dst[temp_ost], 1);
	params->len++;
}

void	ft_hexal_up(unsigned long long n, t_ps *params)
{
	int		temp_ost;
	char	dst[17] = "0123456789ABCDEF";

	if (n >= 16)
		ft_hexal_up(n / 16, params);
	temp_ost = n % 16;
	write (1, &dst[temp_ost], 1);
	params->len++;
}

int	ft_lennbr_hex(unsigned int h)
{
	int	hex;

	hex = 1;
	while (h > 15)
	{
		h /= 16;
		hex++;
	}
	return (hex);
}

int	ft_lennbr_point(unsigned long long h)
{
	int	hex;

	hex = 1;
	while (h > 15)
	{
		h /= 16;
		hex++;
	}
	return (hex + 2);
}

void	ft_hexal_point(unsigned long long n, t_ps *params)
{
	int		temp_ost;
	char	dst[17] = "0123456789abcdef";

	ft_putstr_fd("0x", params);
	if (n >= 16)
		ft_hexal_low(n / 16, params);
	temp_ost = n % 16;
	write (1, &dst[temp_ost], 1);
	params->len++;
}
