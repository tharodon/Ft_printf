#include "ft_printf.h"

void	ft_putnbr_unsigned(unsigned int n)
{
	char	tmp;

	if (n < 0)
	{
		write (1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr_unsigned(n / 10);
	tmp = (n % 10) + '0';
	write (1, &tmp, 1);
}
